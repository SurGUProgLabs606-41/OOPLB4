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