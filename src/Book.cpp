/**
 * @file Book.cpp
 * @brief Реализация методов класса Book.
 *
 * @details
 * Реализует требование пункта 4 лабораторной работы:
 * копирование и присваивание характеристик книги.
 *
 * Также реализует получение автора, названия и ISBN,
 * а также вывод полной информации о книге.
 */

#include "Book.h"
#include <iostream>

using namespace std;

/**
 * @brief Конструктор книги.
 * @param title Название книги.
 * @param isbn ISBN книги.
 * @param pages Количество страниц.
 * @param publisher Название издательства.
 * @param author Имя автора книги.
 *
 * Инициализирует виртуальный базовый класс Publication,
 * промежуточный класс PrintedPublication и поле author.
 */
Book::Book(const string& title, const string& isbn, int pages,
           const string& publisher, const string& author)
    : Publication(title, isbn),
      PrintedPublication(title, isbn, pages, publisher),
      author(author) {}

/**
 * @brief Конструктор копирования книги.
 * @param other Исходная книга для копирования.
 *
 * Копирует данные базового класса Publication,
 * характеристики PrintedPublication и имя автора.
 */
Book::Book(const Book& other)
    : Publication(other),
      PrintedPublication(other),
      author(other.author) {}

/**
 * @brief Оператор присваивания книги.
 * @param other Книга, данные которой присваиваются.
 * @return Ссылка на текущий объект.
 *
 * Копирует характеристики печатного издания
 * и имя автора. Проверяет самоприсваивание.
 */
Book& Book::operator=(const Book& other)
{
    if (this != &other)
    {
        PrintedPublication::operator=(other);
        author = other.author;
    }

    return *this;
}

/**
 * @brief Возвращает имя автора книги.
 * @return Значение поля author.
 */
string Book::getAuthor() const
{
    return author;
}

/**
 * @brief Возвращает название книги.
 * @return Значение поля title.
 */
string Book::getTitle() const
{
    return title;
}

/**
 * @brief Возвращает ISBN книги.
 * @return Значение поля isbn.
 */
string Book::getISBN() const
{
    return isbn;
}

/**
 * @brief Выводит информацию о книге.
 *
 * Отображает название, ISBN, автора, количество страниц
 * и название издательства.
 */
void Book::printInfo() const
{
    cout << "Книга: " << title
         << "\nISBN: " << isbn
         << "\nАвтор: " << author
         << "\nСтраниц: " << pages
         << "\nИздательство: " << publisher << "\n";
}
