#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <fstream>

int cannibals_number = 10; // number of threads
int pot; // pot for food
int max_pot; // pot capacity
bool out_of_food; // true, if pot is empty
static int time_passed; // time passed

pthread_mutex_t mutex; // mutex for threads

bool is_writing = false; // true, if we should write to file
std::string input_name; // name of input file
std::string output_name; // name of output file

// check if time is over
bool isFinish() {
    return time_passed >= cannibals_number;
}

// function for cannibal thread (Consumer)
void *cannibal(void *param) {
    int cNum = *((int *) param);

    // if time is over, finish
    while (!isFinish()) {
        ++time_passed;
        sleep(3);
        pthread_mutex_lock(&mutex); // start of critical section
        std::string message;
        if (pot <= 0) {  // check if pot is empty
            out_of_food = true;
            message = "is waiting dinner...";
        } else {
            --pot;
            message = "had a dinner";
        }
        // print message about cannibal (eating process)
        printf("[Consumer] Cannibal %d: %s\n", cNum, &message[0]);
        printf("[Consumer] Number of food left = %i\n", pot);

        if (is_writing) {
            FILE *output = fopen(&output_name[0], "a");
            fprintf(output, "[Consumer] Cannibal %d: %s\n", cNum, &message[0]);
            fprintf(output, "[Consumer] Number of food left = %i\n", pot);
            fclose(output);
        }

        pthread_mutex_unlock(&mutex); // end of critical section
    }

    return nullptr;
}

// function for cook thread (Producer)
void *fCook(void *param) {
    // if time is over, finish
    while (!isFinish()) {
        sleep(3);
        if (out_of_food) {
//            ++time_passed;
            pthread_mutex_lock(&mutex); //  start of critical section

            int cooked = max_pot;
            pot += cooked;
            out_of_food = false;

            // print message about cooking
            printf("[Producer] Cook: cooked %i food.\n", cooked);
            printf("[Producer] Number of food left = %i\n", pot);

            if (is_writing) {
                FILE *output = fopen(&output_name[0], "a");
                fprintf(output, "[Producer] Cook: cooked %i food.\n", cooked);
                fprintf(output, "[Producer] Number of food left = %i\n", pot);
                fclose(output);
            }

            pthread_mutex_unlock(&mutex); // end of critical section
        }
    }

    return nullptr;
}

// input
void FileInput() {
    std::ifstream input;
    do {
        std::cout << "Enter input file name: ";
        std::cin >> input_name;

        input.open(input_name);
        if (!input.is_open())
            std::cout << "Could not open the file - " << input_name << "" << std::endl;
    } while (!input.is_open());

    input >> max_pot;
    pot = max_pot;
    input >> cannibals_number;

    input.close();
}

// output
void FileOutput() {
    std::cout << "Enter output file name: "; // check if we need read from file
    std::cin >> output_name;
    is_writing = true;

    // clear file
    std::ofstream output(output_name, std::ofstream::out | std::ofstream::trunc);
    output.close();
}

void ConsoleInput() {
    std::cout << "Input pot capacity: ";
    std::cin >> max_pot;
    while (max_pot <= 0) {
        std::cout << "Input pot capacity: ";
        std::cin >> max_pot;
    }
    pot = max_pot;
    std::cout << "Input number of canibals: ";
    std::cin >> cannibals_number;
    while (cannibals_number <= 0) {
        std::cout << "Input number of canibals: ";
        std::cin >> cannibals_number;
    }
}


int main(int argc, char* argv[]) {
    if (argc != 5) {  // if argc != 5, we need read from console
        std::cout << "Read from file? (Y/n) ";
        char answer;
        std::cin >> answer;
        if (answer == 'Y') {
            FileInput();
        } else {
            std::cout << "Read from console? (Y/n) ";
            std::cin >> answer;
            if (answer == 'Y') {
                ConsoleInput();
            } else {
                max_pot = 5 + rand() % 11;
                std::cout << "max_pot = " << max_pot << std::endl;
                pot = max_pot;
            }
        }
        // check if we need write to file
        std::cout << "Write to file? (Y/n) ";
        std::cin >> answer;
        if (answer == 'Y') {
            FileOutput();
        }
    } else {
        max_pot = atoi(argv[1]);
        pot = max_pot;
        cannibals_number = atoi(argv[2]);
        input_name = argv[3];
        output_name = argv[4];
        is_writing = true;
    }



    // mutex init
    pthread_mutex_init(&mutex, nullptr);
    time_passed = 0;

    // create threads array
    pthread_t thread_cannibals[cannibals_number];
    int cannibals[cannibals_number];
    pthread_t cook;

    // create cannibals and cook threads
    for (int i = 0; i < cannibals_number; ++i) {
        cannibals[i] = i + 1;
        pthread_create(&thread_cannibals[i], NULL, cannibal, (void *) (cannibals + i));
    }
    pthread_create(&cook, NULL, fCook, NULL);

    // join threads
    for (int i = 0; i < cannibals_number; ++i) {
        pthread_join(thread_cannibals[i], nullptr);
    }
    pthread_join(cook, nullptr);

    // result
    std::cout << std::endl << "Result pot: " << pot << std::endl;

    if (is_writing) {
        std::ofstream output(output_name, std::ios_base::app);
        output << std::endl << "Result pot: " << pot << std::endl;
        output.close();
    }

    return 0;
}
