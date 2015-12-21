#Реализация стека на линейном односвязном списке 

**Содержание:**

- [Постановка задачи](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Постановка-задачи)
- [Руководство пользователя](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Руководство-пользователя)
- [Руководство программиста](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Руководство-программиста)
	- [Используемые инструменты](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Используемые-инструменты)
	- [Общая структура проекта](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Общая-структура-проекта)
	- [Описание структуры программы](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Описание-структуры-программы)
	- [Описание структур данных](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Описание-структур-данных)
		- [Структура данных "список"](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Структура-данных-список)
		- [Структура данных "стек"](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Структура-данных-стек)
	- [Описание алгоритмов](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Описание-алгоритмов)
		- [Алгоритм перевода в постфиксную запись](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Алгоритм-перевода-в-постфиксную-запись)
		- [Алгоритм подсчета выражения в постфиксной записи](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Алгоритм-подсчета-выражения-в-постфиксной-записи)
- [Заключение](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Заключение)
- [Литература](https://github.com/Maxim-Doronin/mp2-lab3-lists-stack#Литература)
 
##Постановка задачи
**Цель данной лабораторной работы** — разработать на языке программирования С++ статическую библиотеку, реализующую динамическую структуру данных — стек, основанный на динамической структуре — список. 

Написать тестирующую программу для каждой структуры данных с помощью Google C++ Testing Framework.
 
В качестве примера реализации стеков, разработать алгоритм преобразования инфиксной записи арифметических выражений в постфиксную. Создать консольное приложение, демонстрирующее работу алгоритма, где входные данные — арифметическое символьное выражение в инфиксном виде и значения каждого параметра, а результат — запись исходного арифметического символьного выражения в постфиксном виде, численный результат.

Написать консольные приложения для демонстрации работы списков и стеков.

##Руководство пользователя
###*Запуск приложения и ввод данных*

Данная программа предназначена для перевода символьного арифметического выражения из инфиксной записи в постфиксную и последующего вычисления результата на основе данных о каждой символьной переменной, введенных пользователем.

Чтобы запустить программу, необходимо открыть исполняемый файл `sample_postfix.exe` и далее следовать инструкциям программы.

Пример:

1. Введите арифметическое выражение и нажмите клавишу "Ввод"
![start](/img/start.png)
2. Введите значение каждой из символьных переменных, нажимая клавишу "Ввод" после каждого введенного значения.
3. Получите преобразованное выражение и численный результат.
![finish](/img/finish.png)

Для завершения работы нажмите любую клавишу.


##Руководство программиста 

###*Используемые инструменты*

В ходе лабораторной работы использовались следующие инструменты:

- Система контроля версий Git. 
- Фреймворк для написания автоматических тестов Google Test.
- Среда разработки Microsoft Visual Studio (2010 или старше).


###*Общая структура проекта*

Структура проекта:

- `gtest` — библиотека Google Test.
- `img` — директория с изображениями, используемых в отчете к лабораторной работе. 
- `include` — директория для размещения заголовочных файлов.
- `samples` — директория для размещения тестового приложения.
- `sln` — директория с файлами решений и проектов для Visual Studio 2010
- `src` — директория для размещения исходных кодов (cpp-файлы).
- `test` — директория с модульными тестами и основным тестовым приложением, инициализирующим запуск тестов.
- `README.md` — отчет о выполненной лабораторной работе.
- Служебные файлы
    - `.gitignore` — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.


###*Описание структуры программы*

Программа состоит из 7 проектов:

- `stack` — статическая библиотека, которая содержит объявление и реализацию шаблонных классов *`NODE`*, *`List`* и *`Stack`*
	- *`NODE`* — описывает сущность "узел" списка. "Узел" хранит в себе значение "ключа" и указатель на следующий узел, то есть на объект такого же класса.
	- *`List`* — класс "список", агрегирующий в себе класс *`NODE`*.
	- *`Stack`* — класс "стек", агрегирующий в себе класс *`List`*.
- `postfix_notation` — статическая библиотека, использующая функционал класса *`Stack`*, содержащая класс *`Postfix`* со статическими методами перевода арифметического выражения из инфиксной формы в постфиксную и вычисления полученного выражения. Содержит 2 метода
	- `postfix_notation` — метод непосредственного перевода выражения в постфиксную запись, учитывающая корректность данных. Входные и выходные данные — строковый тип.
	- `postfix_calculation` — метод вычисления результата, считывающая аргументы арифметического выражения из потока данных. Входные данные — строковый тип (выражение в постфиксной форме), выходные — вещественное число. Так же учитывает корректность введенных данных, и соответствие количества операндов и операций.
- `sample_list` — консольное приложение, демонстрирующее работу методов класса *`List`*
- `sample_stack` — консольное приложение, демонстрирующее работу методов класса *`Stack`*
- `sample_postfix` — консольное приложение, содержащее функцию `main`, которая запрашивает у пользователя выражение в инфиксной записи и выводит выражение в постфиксной форме и результат, полученные от функций библиотеки `postfix_notation`.
- `gtest` — фреймворк Google Test.
- `tests` — консольное приложение, использующее библиотеку Google Test, проверяющее корректность реализации классов *`List`* и *`Stack`*. Содержит 46 тестов.
	

###*Описание структур данных*

####Структура данных "список"

Односвязный линейный список — динамическая структура данных, состоящая из однотипных "узлов", каждый из которых содержит данные определенного типа и указатель на последующий узел списка. Указатель последнего элемента списка равен нулю, что является признаком конца списка. Указателем на список является указатель на его первый элемент (pFirst).

![list](/img/list.png)

Принципиальным преимуществом перед линейным массивом является структурная гибкость: порядок элементов связного списка может не совпадать с порядком расположения элементов данных в памяти компьютера, а порядок обхода списка всегда явно задаётся его внутренними связями.

В данной лабораторной работе структура данных "список" представлена в виде класса *`List`*, который содержит в себе следующие методы:

- Конструктор по умолчанию.
- Конструктор копирования списков.
- Деструктор.
- `print` — метод печати элементов списка.
- `search` — метод поиска элемента с заданным ключом, возвращающая указатель на элемент
- `searchPrev` — скрытый метод поиска элемента, предшествующего элементу с заданным ключом.
- `erase` — перегруженный метод удаления элемента с заданным ключом или по указателю на элемент.
- `insertFirst` — метод создания элемента с заданным ключом и вставки его в начало списка.
- `insertLast` — метод создания элемента с заданным ключом и вставки его в конец списка.
- `insertBefore` — метод вставки элемента, на который передан указатель, до элемента с заданным ключом.
- `insertAfter` — метод вставки элемента, на который передан указатель, после элемента с заданным ключом.
- `getFirst` — метод, возвращающий указатель на первый элемент списка.

Представленный набор методов достаточен для реализации других структур данных, например, стеков, с использованием этого класса, а так же для решения типовых задач. Пример использования этой структуры данных содержится в приложении `sample_list.exe`.

Класс *`List`* реализован с использованием шаблонов для покрытия его использования с различными типами данных.

####Структура данных "стек"

Стек — динамическая структура данных, представляющая собой список элементов, организованных по принципу FILO (англ. first in — last out, «последним пришёл — первым вышел»).

В данной лабораторной работе структура данных "стек" реализована в виде односвязного линейного списка, то есть каждый элемент содержит помимо хранимой информации в стеке указатель на следующий элемент стека. 

![stack](/img/Stack.png)

Программный вид стека используется для обхода структур данных, например, дерево или граф. При использовании рекурсивных функций также будет применяться стек, но аппаратный его вид. Кроме этих назначений, стек используется для организации стековой машины, реализующей запись и вычисления в постфиксной форме арифметических выражений (последний алгоритмы реализован в данной лабораторной работе в качестве примера использования стеков).

В данной лабораторной работе структура данных "стек" представлена в виде класса *`Stack`*, который агрегирует в себя объект класса *`List`* и содержит следующие методы:

- Конструктор по умолчанию, который явно вызывает конструктор класса *`List`*.
- Конструктор копирования.
- Деструктор.
- `isEmpty` — метод проверки стека на пустоту
- `isFull` — метод проверки стека на полноту. По факту, проверяется наличие доступной памяти в виртуальном адресном пространстве программы для создания нового узла списка.
- `push` — метод добавления элемента с заданным значением на вершину стека.
- `pop` — метод изъятия элемента с вершины стека. Метод возвращает значение элемента.
- `look` — метод просмотра элемента на вершине стека.

Методы, реализованные в классе *`Stack`* необходимы и достаточны для полноценного использования этой структуры данных. Пример использования этой структуры данных содержится в приложении `sample_stack.exe`.

Класс *`Stack`* реализован с использованием шаблонов для покрытия его использования с различными типами данных.


###*Описание алгоритмов*

####Алгоритм перевода в постфиксную запись

Описание алгоритма перевода из инфиксной записи в постфиксную:

1. Каждой операции ставится приоритет

	- Операциям умножения `*` и деления `/` наивысший приоритет, равный 3.
	- Операциям сложения `+` и вычитания `-` приоритет 2
	- Операции открывающей скобки `(` приоритет 1.
	- Операции равенства `=` приоритет 0.

2. Создается 2 стека: стек для хранения текущей постфиксной формы `trackStack` и стек для хранения операций `opStack`.
3. Выражение просматривается слева-направо, при этом возможно 4 случая:

	1. Встретился операнд. Тогда он добавляется в стек `trackStack`.
	2. Встретилась операция, приоритет которой выше, чем приоритет операции, лежащей на вершине стека `opStack`, или стек `opStack` пуст. В этом случае операция добавляется в стек для хранения операций `opStack`.
	3. Встретилась операция, приоритет которой равен или ниже приоритета операции, лежащей на вершине стека `opStack`. В этом случае все операции, приоритет которых больше данной перекладываются в стек `trackStack` до тех пор, пока на вершине стека `opStack` не появится операции с меньшим приоритетом или `opStack` не станет пустым. Новая же операция добавляется в стек хранения операций.
	4. Встретилась операция закрывающей скобки. В этом случае из стека `opStack` перекладываются все операции в `trackStack` до первого вхождения операции открывающей скобки. Операция открывающей скобки удаляется из стека операций.

4. Если выражение закончилось, то все операции из стека операций `opStack` перекладываются в стек хранения текущей постфиксной формы `trackStack`.

####Алгоритм подсчета выражения в постфиксной записи

Описание алгоритма вычисления арифметического выражения в постфиксной форме:

1. Создается один стек с вещественным типом данных `trackStack`.
2. Выражение просматривается слева-направо, при этом возможно 2 случая:

	1. Встретился операнд. В этом случае от пользователя запрашивается его значение (в случае, если ранее значение для данного символьного операнда не запрашивалось) и добавляется на вершину стека `trackStack`.
	2. Встретилась операция. Тогда из стека `trackStack` изымаются 2 операнда, над ними совершается операция, результат операции снова добавляется в стек.

3. При достижении конца арифметического выражения, в стеке будет находиться единственный элемент — численный результат выражения.

##Заключение
В ходе лабораторной работы была разработана программа, удовлетворяющая поставленным задачам. Структура стек и список были реализованы с использованием шаблонных классов, так как этого требовал алгоритм преобразования записи выражения. Написаны примеры использования списков и стеков, демонстрирующие работу методов соответствующих классов.

В процессе было написано 46 тестов, которые покрывают всевозможные ситуации использования методов класса. Все тесты успешно пройдены.

Реализован алгоритм перевода арифметического выражения из инфиксной формы в постфиксную и вычисление его результата.


##Литература

- Альфред В. Ахо, Джон Хопкрофт, Джеффри Д. Ульман. Структуры данных и алгоритмы = Data Structures and Algorithms. — М.: Вильямс, 2000. — 384 с.
- Майкл Мейн, Уолтер Савитч. Структуры данных и другие объекты в C++ = Data Structures and Other Objects Using C++. — 2-е изд. — М.: Вильямс, 2002. — 832 с.

