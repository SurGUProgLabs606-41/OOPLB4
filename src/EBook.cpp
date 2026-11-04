/**
 * @file EBook.cpp
 * @brief Реализация методов класса EBook.
 *
 * @details
 * Реализует требование пункта 4 лабораторной работы:
 * копирование и присваивание характеристик электронной книги.
 *
 * Также реализует получение названия и ISBN,
 * а также вывод информации об электронной книге.
 */

#include "EBook.h"
#include <iostream>

using namespace std;

/**
 * @brief Конструктор электронной книги.
 * @param title Название книги.
 * @param isbn ISBN книги.
 * @param fileSize Размер электронного файла в мегабайтах.
 * @param format Формат электронного файла.
 *
 * Инициализирует виртуальный базовый класс Publication
 * и промежуточный класс DigitalPublication.
 */
EBook::EBook(const string &title, const string &isbn,
             double fileSize, const string &format)
    : Publication(title, isbn),
      DigitalPublication(title, isbn, fileSize, format) {}

/**
 * @brief Конструктор копирования электронной книги.
 * @param other Исходная электронная книга для копирования.
 *
 * Копирует характеристики базового класса Publication
 * и промежуточного класса DigitalPublication.
 */
EBook::EBook(const EBook &other)
    : Publication(other), DigitalPublication(other) {}

/**
 * @brief Оператор присваивания электронной книги.
 * @param other Электронная книга, данные которой присваиваются.
 * @return Ссылка на текущий объект.
 *
 * Копирует характеристики DigitalPublication
 * и проверяет самоприсваивание.
 */
EBook &EBook::operator=(const EBook &other)
{
    if (this != &other)
        DigitalPublication::operator=(other);

    return *this;
}

/**
 * @brief Возвращает название электронной книги.
 * @return Значение поля title.
 */
string EBook::getTitle() const
{
    return title;
}

/**
 * @brief Возвращает ISBN электронной книги.
 * @return Значение поля isbn.
 */
string EBook::getISBN() const
{
    return isbn;
}

/**
 * @brief Выводит информацию об электронной книге.
 *
 * Отображает название, ISBN, размер файла и формат.
 */
void EBook::printInfo() const
{
    cout << "Электронная книга: " << title
         << "\nISBN: " << isbn
         << "\nРазмер файла: " << fileSize
         << " MB\nФормат: " << format << "\n";
}
