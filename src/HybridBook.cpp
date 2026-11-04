/**
 * @file HybridBook.cpp
 * @brief Реализация методов класса HybridBook.
 *
 * @details
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 4. Реализация конструктора копирования
 * и оператора присваивания.
 *
 * Пункт 7. Реализация класса с множественным наследованием.
 * Инициализация общей виртуальной базы Publication
 * и обеих родительских частей: Book и DigitalPublication.
 *
 * Также реализуется вывод характеристик печатной
 * и электронной частей гибридной книги.
 */

#include "HybridBook.h"
#include <iostream>

using namespace std;

/**
 * @brief Параметризованный конструктор гибридной книги.
 *
 * @param title Название книги.
 * @param isbn Международный стандартный номер книги.
 * @param pages Количество страниц.
 * @param publisher Издательство.
 * @param author Автор книги.
 * @param fileSize Размер электронного файла в мегабайтах.
 * @param format Формат электронного файла.
 *
 * @details
 * Инициализирует виртуальную базу Publication,
 * а также родительские классы Book и DigitalPublication.
 *
 * Publication инициализируется непосредственно в HybridBook,
 * поскольку является виртуальной базой.
 */
HybridBook::HybridBook(const string &title, const string &isbn, int pages,
                       const string &publisher, const string &author,
                       double fileSize, const string &format)
    : Publication(title, isbn),
      Book(title, isbn, pages, publisher, author),
      DigitalPublication(title, isbn, fileSize, format) {}

/**
 * @brief Конструктор копирования гибридной книги.
 *
 * @param other Объект, который копируется.
 *
 * @details
 * Копирует виртуальную базу Publication и обе родительские части:
 * Book и DigitalPublication.
 */
HybridBook::HybridBook(const HybridBook &other)
    : Publication(other), Book(other), DigitalPublication(other) {}

/**
 * @brief Оператор присваивания гибридной книги.
 *
 * @param other Объект, данные которого присваиваются.
 * @return Ссылка на текущий объект.
 *
 * @details
 * Проверяет самоприсваивание.
 * Затем копирует данные печатной книги и электронного издания
 * с помощью операторов присваивания родительских классов.
 */
HybridBook &HybridBook::operator=(const HybridBook &other)
{
    if (this != &other)
    {
        Book::operator=(other);
        DigitalPublication::operator=(other);
    }

    return *this;
}

/**
 * @brief Получает название гибридной книги.
 *
 * @return Название книги.
 */
string HybridBook::getTitle() const
{
    return title;
}

/**
 * @brief Получает ISBN гибридной книги.
 *
 * @return Международный стандартный номер книги.
 */
string HybridBook::getISBN() const
{
    return isbn;
}

/**
 * @brief Проверяет, является ли гибридная книга электронной.
 *
 * @return true, поскольку гибридная книга имеет электронную версию.
 */
bool HybridBook::isDigital() const
{
    return true;
}

/**
 * @brief Выводит полную информацию о гибридной книге.
 *
 * @details
 * Отображает характеристики печатного издания:
 * название, ISBN, автора, количество страниц и издательство.
 *
 * Также отображает характеристики электронного издания:
 * размер файла и формат.
 */
void HybridBook::printInfo() const
{
    cout << "Гибридная книга: " << title << "\nISBN: " << isbn
         << "\nАвтор: " << author << "\nСтраниц: " << pages
         << "\nИздательство: " << publisher << "\nРазмер файла: " << fileSize
         << " MB\nФормат: " << format << "\n";
}
