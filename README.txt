Лабораторная работа №4 ООП — Вариант 8

Сборка на macOS/Linux вручную (из папки Lab4):

Компиляция:
g++ -std=c++17 -Wall -Wextra -fPIC -Iinclude -c \
src/Publication.cpp \
src/PrintedPublication.cpp \
src/DigitalPublication.cpp \
src/Book.cpp \
src/Magazine.cpp \
src/EBook.cpp \
src/HybridBook.cpp

Перемешенние в папку:
mv *.o build/

Создание статической библиотеки
ar rcs lib/liblab4.a \
build/Publication.o \
build/PrintedPublication.o \
build/DigitalPublication.o \
build/Book.o \
build/Magazine.o \
build/EBook.o \
build/HybridBook.o

Компиляция тестовой программы:
g++ -std=c++17 -Wall -Wextra -Iinclude \
src/main.cpp lib/liblab4.a \
-o bin/test_static

Запуск:
cd data
../bin/test_static

Проверка на статичность:
otool -L bin/test_static


Динамическая библиотека:
g++ -dynamiclib -o lib/liblab4.dylib \
build/Publication.o \
build/PrintedPublication.o \
build/DigitalPublication.o \
build/Book.o \
build/Magazine.o \
build/EBook.o \
build/HybridBook.o

Компиляция динамической библиотеки:
g++ -std=c++17 -Wall -Wextra -Iinclude \
src/main.cpp -Llib -llab4 -o bin/test_dynamic

Переход в папку:
cd data

Запуск программы:
DYLD_LIBRARY_PATH=../lib ../bin/test_dynamic

Важно: publications.txt должен находиться в текущей рабочей папке при запуске программы.


СБОРКА ПОД WINDOWS
mingw-w64 для обращения через терминал
Компиляция классов:
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -Iinclude -DBUILDING_DLL -c src/Publication.cpp -o build/windows/Publication.o
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -Iinclude -DBUILDING_DLL -c src/PrintedPublication.cpp -o build/windows/PrintedPublication.o
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -Iinclude -DBUILDING_DLL -c src/DigitalPublication.cpp -o build/windows/DigitalPublication.o
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -Iinclude -DBUILDING_DLL -c src/Book.cpp -o build/windows/Book.o
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -Iinclude -DBUILDING_DLL -c src/Magazine.cpp -o build/windows/Magazine.o
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -Iinclude -DBUILDING_DLL -c src/EBook.cpp -o build/windows/EBook.o
x86_64-w64-mingw32-g++ -std=c++17 -Wall -Wextra -Iinclude -DBUILDING_DLL -c src/HybridBook.cpp -o build/windows/HybridBook.o

Создание библиотек: 
.dll - динамическая. .lib - библиотека импорта
x86_64-w64-mingw32-g++ -shared \
-o lib/windows/lab4.dll \
-Wl,--out-implib,lib/windows/lab4.lib \
build/windows/Publication.o \
build/windows/PrintedPublication.o \
build/windows/DigitalPublication.o \
build/windows/Book.o \
build/windows/Magazine.o \
build/windows/EBook.o \
build/windows/HybridBook.o

Компиляция:
g++ -std=c++17 -Iinclude src/main.cpp -Llib/windows -llab4 -o test.exe

Запуск:
./test.exe



СБОРКА ПОД LINUX
zig для обращения через терминал

Компиляция классов:
zig c++ -target x86_64-linux-musl -std=c++17 -fPIC -Iinclude -c src/Publication.cpp -o build/linux/Publication.o
zig c++ -target x86_64-linux-musl -std=c++17 -fPIC -Iinclude -c src/PrintedPublication.cpp -o build/linux/PrintedPublication.o
zig c++ -target x86_64-linux-musl -std=c++17 -fPIC -Iinclude -c src/DigitalPublication.cpp -o build/linux/DigitalPublication.o
zig c++ -target x86_64-linux-musl -std=c++17 -fPIC -Iinclude -c src/Book.cpp -o build/linux/Book.o
zig c++ -target x86_64-linux-musl -std=c++17 -fPIC -Iinclude -c src/Magazine.cpp -o build/linux/Magazine.o
zig c++ -target x86_64-linux-musl -std=c++17 -fPIC -Iinclude -c src/EBook.cpp -o build/linux/EBook.o
zig c++ -target x86_64-linux-musl -std=c++17 -fPIC -Iinclude -c src/HybridBook.cpp -o build/linux/HybridBook.o

Сборка .so:
zig c++ -target x86_64-linux-musl -shared \
-o lib/linux/liblab4.so \
build/linux/Publication.o \
build/linux/PrintedPublication.o \
build/linux/DigitalPublication.o \
build/linux/Book.o \
build/linux/Magazine.o \
build/linux/EBook.o \
build/linux/HybridBook.o

Компиляция:
g++ -std=c++17 -Iinclude src/main.cpp \
-Llib/linux -llab4 \
-Wl,-rpath,'$ORIGIN/lib/linux' \
-o test_linux

Запуск:
./test_linux


Проверка формата библиотек не запуская их:
file lib/windows/lab4.dll
file lib/windows/lab4.lib
file lib/linux/liblab4.so


Запуск UML-диаграмм
option + D

doxygen Doxyfile // Собрать документ
open docs/html/index.html // Запуск

Информация:
privet - доступ в пределах текущего класса.
protected - доступ в пределах текущего и всех дочерних от него классах. Дочерний класса получает прямой доступ к таким переменным.
public - общий доступ (внутри и за пределами класса).

virtual - позволяет обращаться из базового класса к дочернему. Но если в дочернем нету такого метода, то обращаться будет к методу базовому.
В деструктору применяется чтобы не было утечек памяти. Так если этого не прописывать и обращаться через базовый класс к дочернему, то вызывается только очистка базового класса, но не дочернего.
Дочерний класс в свою очередь вызывает дестрктор базового класса.
Если мы знаем что класс участвует в наследовании, то следует его деструктор помечать как virtual, чтобы избежать утечек памяти.
virtual string getISBN() const = 0; - чисто виртуальный функция. Так как в базовом классе он не прописан, но приписывается в дочернем классе и приравнивается к 0. 
Благодаря этому по умолчанию будет вызвана ошибка, если метод не определён в дочернем классе. Благодаря такому, класс становиться абстрактным и его объект создавать нельзя.
virtual в классе прописывается чтобы избежать наследования из других дочерних классов, если один и тот же базовый метод у них одинаковый.

override - используется для переопределяемого виртуального метода, чтобы компилятор знал, что базовый класс изменён и таким образом находит ошибку (если они будут отличаться)

final - запрещает переопределать метод в дочернем класса (только к виртуальным методам).

При множественном наследовании порядок классов определяется вызовом, а деструкторов в обратном порядке.

где у меня полиморфные.
асбтрактный класс - хотя бы одна виртуальная функция.





g++	- Компилятор C++
-std=c++17 - Использовать стандарт языка C++17
-Wall - Включить основные предупреждения компилятора
-Wextra - Включить дополнительные предупреждения
-fPIC - Создавать позиционно-независимый код, необходимый для динамических библиотек
-Iinclude - Искать подключаемые заголовочные файлы (.h) в папке include
-c - Только компилировать, не выполнять компоновку (linking)


ar - Утилита для создания и изменения архивов объектных файлов
r - Добавить файлы в архив или заменить существующие
c - Создать архив, если его ещё нет
s - Создать индекс символов для ускорения компоновки


g++ - Компилятор C++
-dynamiclib - Создать динамическую библиотеку (macOS)
-o - Указать имя и путь выходного файла


DYLD_LIBRARY_PATH - Переменная окружения macOS, задающая дополнительные пути поиска динамических библиотек