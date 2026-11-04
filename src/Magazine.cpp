/**
 * @file Magazine.cpp
 * @brief Реализация методов класса Magazine.
 *
 * @details
 * Реализует требование пункта 4 лабораторной работы:
 * копирование и присваивание характеристик журнала.
 *
 * Также реализует получение названия и ISBN,
 * а также вывод информации о журнале.
 */

#include "Magazine.h"
#include <iostream>

using namespace std;

/**
 * @brief Конструктор журнала.
 * @param title Название журнала.
 * @param isbn ISBN журнала.
 * @param pages Количество страниц.
 * @param publisher Название издательства.
 * @param issueNumber Номер выпуска журнала.
 *
 * Инициализирует виртуальный базовый класс Publication,
 * промежуточный класс PrintedPublication и номер выпуска.
 */
Magazine::Magazine(const string &title, const string &isbn, int pages,
                   const string &publisher, int issueNumber)
    : Publication(title, isbn),
      PrintedPublication(title, isbn, pages, publisher),
      issueNumber(issueNumber) {}

/**
 * @brief Конструктор копирования журнала.
 * @param other Исходный журнал для копирования.
 *
 * Копирует данные базового класса Publication,
 * характеристики PrintedPublication и номер выпуска.
 */
Magazine::Magazine(const Magazine &other)
    : Publication(other),
      PrintedPublication(other),
      issueNumber(other.issueNumber) {}

/**
 * @brief Оператор присваивания журнала.
 * @param other Журнал, данные которого присваиваются.
 * @return Ссылка на текущий объект.
 *
 * Копирует характеристики печатного издания
 * и номер выпуска. Проверяет самоприсваивание.
 */
Magazine &Magazine::operator=(const Magazine &other)
{
    if (this != &other)
    {
        PrintedPublication::operator=(other);
        issueNumber = other.issueNumber;
    }

    return *this;
}

/**
 * @brief Возвращает название журнала.
 * @return Значение поля title.
 */
string Magazine::getTitle() const
{
    return title;
}

/**
 * @brief Возвращает ISBN журнала.
 * @return Значение поля isbn.
 */
string Magazine::getISBN() const
{
    return isbn;
}

/**
 * @brief Выводит информацию о журнале.
 *
 * Отображает название, ISBN, номер выпуска,
 * количество страниц и название издательства.
 */
void Magazine::printInfo() const
{
    cout << "Журнал: " << title
         << "\nISBN: " << isbn
         << "\nНомер выпуска: " << issueNumber
         << "\nСтраниц: " << pages
         << "\nИздательство: " << publisher << "\n";
}
