/**
 * @file DigitalPublication.cpp
 * @brief Реализация методов класса DigitalPublication.
 *
 * @details
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 3. Реализация переопределённой функции isDigital(),
 * возвращающей true.
 *
 * Пункт 4. Реализация конструктора копирования
 * и оператора присваивания.
 *
 * Пункт 5. Увеличение и уменьшение статического счётчика
 * digitalCount при создании и уничтожении электронных объектов.
 *
 * Также реализуется вывод характеристик электронного издания.
 */

#include "DigitalPublication.h"
#include <iostream>

using namespace std;

/**
 * @brief Конструктор электронного издания.
 * @param title Название издания.
 * @param isbn ISBN издания.
 * @param fileSize Размер электронного файла в мегабайтах.
 * @param format Формат электронного файла.
 *
 * Инициализирует базовый класс Publication и собственные поля.
 * Увеличивает статический счётчик электронных изданий.
 */
DigitalPublication::DigitalPublication(const string &title, const string &isbn,
                                         double fileSize, const string &format)
    : Publication(title, isbn), fileSize(fileSize), format(format)
{
    ++digitalCount;
}

/**
 * @brief Конструктор копирования электронного издания.
 * @param other Исходный объект для копирования.
 *
 * Копирует данные базового класса Publication,
 * размер файла и формат электронного издания.
 * Увеличивает счётчик электронных изданий.
 */
DigitalPublication::DigitalPublication(const DigitalPublication &other)
    : Publication(other), fileSize(other.fileSize), format(other.format)
{
    ++digitalCount;
}

/**
 * @brief Оператор присваивания электронного издания.
 * @param other Объект, данные которого присваиваются.
 * @return Ссылка на текущий объект.
 *
 * Копирует данные Publication, размер файла и формат.
 * Счётчик электронных изданий не изменяется,
 * поскольку количество объектов остаётся прежним.
 */
DigitalPublication &DigitalPublication::operator=(const DigitalPublication &other)
{
    if (this != &other)
    {
        Publication::operator=(other);
        fileSize = other.fileSize;
        format = other.format;
    }

    return *this;
}

/**
 * @brief Деструктор электронного издания.
 *
 * Уменьшает статический счётчик digitalCount,
 * поскольку электронный объект перестаёт существовать.
 */
DigitalPublication::~DigitalPublication()
{
    --digitalCount;
}

/**
 * @brief Возвращает размер электронного файла.
 * @return Значение поля fileSize.
 */
double DigitalPublication::getFileSize() const
{
    return fileSize;
}

/**
 * @brief Возвращает формат электронного файла.
 * @return Значение поля format.
 */
string DigitalPublication::getFormat() const
{
    return format;
}

/**
 * @brief Определяет электронный тип издания.
 * @return true, так как данный класс представляет электронное издание.
 */
bool DigitalPublication::isDigital() const
{
    return true;
}

/**
 * @brief Выводит информацию об электронном издании.
 *
 * Отображает название, ISBN, размер файла и формат.
 */
void DigitalPublication::printInfo() const
{
    cout << "Электронное издание: " << title << "\nISBN: "
         << isbn << "\nРазмер файла: " << fileSize
         << " MB\nФормат: " << format << "\n";
}
