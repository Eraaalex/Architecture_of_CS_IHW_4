

# Отчёт

__ФИО/группа:__ Ермолаева Елена Александровна БПИ224

__Вариант:__ 9

__Условие__

__Задача о каннибалах__ 

Племя из N дикарей ест вместе из большого горшка, который вмещает M кусков тушеного миссионера. Когда дикарь хочет обедать, он ест из горшка один кусок, если только горшок не пуст, иначе дикарь будит повара и ждет, пока тот не наполнит горшок. Повар, сварив обед, засыпает. Создать многопоточное приложение, моделирующее обед дикарей. Повар и каждый из дикарей задаются отдельными потоками.

## Метод решения

Программа получает данные о кусках в горшке двумя способами: либо из файла считывает количество кусков, либо задаёт случайное значение в диапазоне [5; 15] (для удобства тестирования).
Далее, из горшка поочередно едят каннибалы (реализовано в функции `cannibal`), пока горшок не пуст (используя mutex, для реализации поочередности).
Программа работает до тех пор, пока не пройдет определенное количество действий.
Горшок может вмещать в себя число кусков из диапазона [0; MaxInt]

___Модель параллельных вычислений:___

В основном потоке происходит ввод данных через консоль, создание потоков (каннибалов) и повара, запуск этих потоков, 
вывод результата на экран, а так же соединение потоков и завершение их работы. Потоки каннибалов и повара обращаются к одному и тому же массиву, поэтому любая операция над этим массивом защищена мьютексом, используется модель производители и потребители. Этот мьютекс запрещает двум потокам
изменять состояние котла (pot). 

## Тесты и результаты

### Тест 1: 

Ввод :
20
10

Вывод программы:
```
[Consumer] Cannibal 6: had a dinner
[Consumer] Number of food left = 19
[Consumer] Cannibal 9: had a dinner
[Consumer] Number of food left = 18
[Consumer] Cannibal 10: had a dinner
[Consumer] Number of food left = 17
[Consumer] Cannibal 7: had a dinner
[Consumer] Number of food left = 16
[Consumer] Cannibal 2: had a dinner
[Consumer] Number of food left = 15
[Consumer] Cannibal 5: had a dinner
[Consumer] Number of food left = 14
[Consumer] Cannibal 1: had a dinner
[Consumer] Number of food left = 13
[Consumer] Cannibal 8: had a dinner
[Consumer] Number of food left = 12
[Consumer] Cannibal 3: had a dinner
[Consumer] Number of food left = 11
[Consumer] Cannibal 4: had a dinner
[Consumer] Number of food left = 10

Result pot: 10
```

### Тест 2:

Ввод :
15
5

Вывод программы:

```
[Consumer] Cannibal 2: had a dinner
[Consumer] Number of food left = 14
[Consumer] Cannibal 5: had a dinner
[Consumer] Number of food left = 13
[Consumer] Cannibal 4: had a dinner
[Consumer] Number of food left = 12
[Consumer] Cannibal 1: had a dinner
[Consumer] Number of food left = 11
[Consumer] Cannibal 3: had a dinner
[Consumer] Number of food left = 10

Result pot: 10

```
### Тест 3:

Ввод :
100
100

Вывод программы:
```
[Consumer] Cannibal 44: had a dinner
[Consumer] Number of food left = 99
[Consumer] Cannibal 59: had a dinner
[Consumer] Number of food left = 98
[Consumer] Cannibal 43: had a dinner
[Consumer] Number of food left = 97
[Consumer] Cannibal 60: had a dinner
[Consumer] Number of food left = 96
[Consumer] Cannibal 35: had a dinner
[Consumer] Number of food left = 95
[Consumer] Cannibal 46: had a dinner
[Consumer] Number of food left = 94
[Consumer] Cannibal 41: had a dinner
[Consumer] Number of food left = 93
[Consumer] Cannibal 45: had a dinner
[Consumer] Number of food left = 92
[Consumer] Cannibal 66: had a dinner
[Consumer] Number of food left = 91
[Consumer] Cannibal 77: had a dinner
[Consumer] Number of food left = 90
[Consumer] Cannibal 42: had a dinner
[Consumer] Number of food left = 89
[Consumer] Cannibal 34: had a dinner
[Consumer] Number of food left = 88
[Consumer] Cannibal 48: had a dinner
[Consumer] Number of food left = 87
[Consumer] Cannibal 68: had a dinner
[Consumer] Number of food left = 86
[Consumer] Cannibal 37: had a dinner
[Consumer] Number of food left = 85
[Consumer] Cannibal 70: had a dinner
[Consumer] Number of food left = 84
[Consumer] Cannibal 49: had a dinner
[Consumer] Number of food left = 83
[Consumer] Cannibal 62: had a dinner
[Consumer] Number of food left = 82
[Consumer] Cannibal 78: had a dinner
[Consumer] Number of food left = 81
[Consumer] Cannibal 33: had a dinner
[Consumer] Number of food left = 80
[Consumer] Cannibal 27: had a dinner
[Consumer] Number of food left = 79
[Consumer] Cannibal 26: had a dinner
[Consumer] Number of food left = 78
[Consumer] Cannibal 36: had a dinner
[Consumer] Number of food left = 77
[Consumer] Cannibal 39: had a dinner
[Consumer] Number of food left = 76
[Consumer] Cannibal 38: had a dinner
[Consumer] Number of food left = 75
[Consumer] Cannibal 29: had a dinner
[Consumer] Number of food left = 74
[Consumer] Cannibal 28: had a dinner
[Consumer] Number of food left = 73
[Consumer] Cannibal 31: had a dinner
[Consumer] Number of food left = 72
[Consumer] Cannibal 22: had a dinner
[Consumer] Number of food left = 71
[Consumer] Cannibal 40: had a dinner
[Consumer] Number of food left = 70
[Consumer] Cannibal 32: had a dinner
[Consumer] Number of food left = 69
[Consumer] Cannibal 19: had a dinner
[Consumer] Number of food left = 68
[Consumer] Cannibal 21: had a dinner
[Consumer] Number of food left = 67
[Consumer] Cannibal 25: had a dinner
[Consumer] Number of food left = 66
[Consumer] Cannibal 30: had a dinner
[Consumer] Number of food left = 65
[Consumer] Cannibal 20: had a dinner
[Consumer] Number of food left = 64
[Consumer] Cannibal 23: had a dinner
[Consumer] Number of food left = 63
[Consumer] Cannibal 12: had a dinner
[Consumer] Number of food left = 62
[Consumer] Cannibal 14: had a dinner
[Consumer] Number of food left = 61
[Consumer] Cannibal 7: had a dinner
[Consumer] Number of food left = 60
[Consumer] Cannibal 24: had a dinner
[Consumer] Number of food left = 59
[Consumer] Cannibal 17: had a dinner
[Consumer] Number of food left = 58
[Consumer] Cannibal 13: had a dinner
[Consumer] Number of food left = 57
[Consumer] Cannibal 72: had a dinner
[Consumer] Number of food left = 56
[Consumer] Cannibal 15: had a dinner
[Consumer] Number of food left = 55
[Consumer] Cannibal 5: had a dinner
[Consumer] Number of food left = 54
[Consumer] Cannibal 6: had a dinner
[Consumer] Number of food left = 53
[Consumer] Cannibal 4: had a dinner
[Consumer] Number of food left = 52
[Consumer] Cannibal 16: had a dinner
[Consumer] Number of food left = 51
[Consumer] Cannibal 18: had a dinner
[Consumer] Number of food left = 50
[Consumer] Cannibal 8: had a dinner
[Consumer] Number of food left = 49
[Consumer] Cannibal 9: had a dinner
[Consumer] Number of food left = 48
[Consumer] Cannibal 74: had a dinner
[Consumer] Number of food left = 47
[Consumer] Cannibal 1: had a dinner
[Consumer] Number of food left = 46
[Consumer] Cannibal 10: had a dinner
[Consumer] Number of food left = 45
[Consumer] Cannibal 11: had a dinner
[Consumer] Number of food left = 44
[Consumer] Cannibal 51: had a dinner
[Consumer] Number of food left = 43
[Consumer] Cannibal 2: had a dinner
[Consumer] Number of food left = 42
[Consumer] Cannibal 56: had a dinner
[Consumer] Number of food left = 41
[Consumer] Cannibal 3: had a dinner
[Consumer] Number of food left = 40
[Consumer] Cannibal 82: had a dinner
[Consumer] Number of food left = 39
[Consumer] Cannibal 84: had a dinner
[Consumer] Number of food left = 38
[Consumer] Cannibal 57: had a dinner
[Consumer] Number of food left = 37
[Consumer] Cannibal 80: had a dinner
[Consumer] Number of food left = 36
[Consumer] Cannibal 86: had a dinner
[Consumer] Number of food left = 35
[Consumer] Cannibal 67: had a dinner
[Consumer] Number of food left = 34
[Consumer] Cannibal 50: had a dinner
[Consumer] Number of food left = 33
[Consumer] Cannibal 75: had a dinner
[Consumer] Number of food left = 32
[Consumer] Cannibal 69: had a dinner
[Consumer] Number of food left = 31
[Consumer] Cannibal 73: had a dinner
[Consumer] Number of food left = 30
[Consumer] Cannibal 79: had a dinner
[Consumer] Number of food left = 29
[Consumer] Cannibal 99: had a dinner
[Consumer] Number of food left = 28
[Consumer] Cannibal 96: had a dinner
[Consumer] Number of food left = 27
[Consumer] Cannibal 87: had a dinner
[Consumer] Number of food left = 26
[Consumer] Cannibal 98: had a dinner
[Consumer] Number of food left = 25
[Consumer] Cannibal 52: had a dinner
[Consumer] Number of food left = 24
[Consumer] Cannibal 76: had a dinner
[Consumer] Number of food left = 23
[Consumer] Cannibal 83: had a dinner
[Consumer] Number of food left = 22
[Consumer] Cannibal 81: had a dinner
[Consumer] Number of food left = 21
[Consumer] Cannibal 85: had a dinner
[Consumer] Number of food left = 20
[Consumer] Cannibal 65: had a dinner
[Consumer] Number of food left = 19
[Consumer] Cannibal 61: had a dinner
[Consumer] Number of food left = 18
[Consumer] Cannibal 100: had a dinner
[Consumer] Number of food left = 17
[Consumer] Cannibal 53: had a dinner
[Consumer] Number of food left = 16
[Consumer] Cannibal 64: had a dinner
[Consumer] Number of food left = 15
[Consumer] Cannibal 63: had a dinner
[Consumer] Number of food left = 14
[Consumer] Cannibal 55: had a dinner
[Consumer] Number of food left = 13
[Consumer] Cannibal 54: had a dinner
[Consumer] Number of food left = 12
[Consumer] Cannibal 94: had a dinner
[Consumer] Number of food left = 11
[Consumer] Cannibal 58: had a dinner
[Consumer] Number of food left = 10
[Consumer] Cannibal 93: had a dinner
[Consumer] Number of food left = 9
[Consumer] Cannibal 97: had a dinner
[Consumer] Number of food left = 8
[Consumer] Cannibal 95: had a dinner
[Consumer] Number of food left = 7
[Consumer] Cannibal 47: had a dinner
[Consumer] Number of food left = 6
[Consumer] Cannibal 71: had a dinner
[Consumer] Number of food left = 5
[Consumer] Cannibal 92: had a dinner
[Consumer] Number of food left = 4
[Consumer] Cannibal 91: had a dinner
[Consumer] Number of food left = 3
[Consumer] Cannibal 90: had a dinner
[Consumer] Number of food left = 2
[Consumer] Cannibal 89: had a dinner
[Consumer] Number of food left = 1
[Consumer] Cannibal 88: had a dinner
[Consumer] Number of food left = 0

Result pot: 0
```


## Дополнительно:

Для запуска программы в командной строке необходимо ввести:

```./8.cpp <pot_capacity> <cannibals_number> <input_file_name> <output_file_name>```

Если ввести неверное количество аргументов, их ввод будет запрошен во время выполнения программы.


Для выполнения критерия на оценку 8 были использованы мьютексы.

1. Описаная модель параллельных вычислений (потребители и производители), используемая при разработке многопоточной программы.

3.	Описаны входные данные программы, включающие вариативные диапазоны, возможные при многократных запусках.

4.	Консольное приложение, решающее задачу с использованием одного варианта синхропримитивов (мьютексов).

5.	Ввод данных в приложение реализован с консоли во время выполнения программы).

6.	Для используемых генераторов случайных чисел описаны их диапазоны и то, как интерпретируются данные этих генераторов.


7. В программу добавлена генерация случайных данных в допустимых диапазонах. (6-7 баллов)

8.	Реализован ввод исходных данных из командной строки при запуске программы вместо ввода параметров с консоли во время выполнения программы. (6-7 баллов)

9. В программу, наряду с выводом в консоль, добавлен вывод результатов в файл. Имя файла для вывода данных задается в командной строке как один из ее параметров. (8 бааллов)

10. Результаты работы программы выводятся на экран и записываются в файл. (8 баллов)





