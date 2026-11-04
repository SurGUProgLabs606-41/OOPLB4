/**
 * @file PrintedPublication.cpp
 * @brief Реализация методов класса PrintedPublication.
 *
 * @details
 * Реализует требование пункта 4 лабораторной работы:
 * копирование и присваивание характеристик промежуточного класса.
 *
 * Также реализует получение количества страниц,
 * названия издательства и вывод информации о печатном издании.
 */

#include "PrintedPublication.h"
#include <iostream>

using namespace std;

/**
 * @brief Конструктор печатного издания.
 * @param title Название издания.
 * @param isbn ISBN издания.
 * @param pages Количество страниц.
 * @param publisher Название издательства.
 *
 * Передаёт название и ISBN базовому классу Publication,
 * а количество страниц и издательство сохраняет в собственных полях.
 */
PrintedPublication::PrintedPublication(const string &title, const string &isbn,
                                         int pages, const string &publisher)
    : Publication(title, isbn), pages(pages), publisher(publisher) {}

/**
 * @brief Конструктор копирования печатного издания.
 * @param other Исходный объект для копирования.
 *
 * Копирует данные базового класса Publication,
 * количество страниц и название издательства.
 */
PrintedPublication::PrintedPublication(const PrintedPublication &other)
    : Publication(other), pages(other.pages), publisher(other.publisher) {}

/**
 * @brief Оператор присваивания печатного издания.
 * @param other Объект, данные которого присваиваются.
 * @return Ссылка на текущий объект.
 *
 * Сначала копирует данные базового класса Publication,
 * затем присваивает количество страниц и название издательства.
 */
PrintedPublication &PrintedPublication::operator=(const PrintedPublication &other)
{
    if (this != &other)
    {
        Publication::operator=(other);
        pages = other.pages;
        publisher = other.publisher;
    }

    return *this;
}

/**
 * @brief Возвращает количество страниц.
 * @return Значение поля pages.
 */
int PrintedPublication::getPages() const
{
    return pages;
}

/**
 * @brief Возвращает название издательства.
 * @return Значение поля publisher.
 */
string PrintedPublication::getPublisher() const
{
    return publisher;
}

/**
 * @brief Выводит характеристики печатного издания.
 *
 * Использует поля базового класса Publication и собственные поля
 * PrintedPublication для отображения полной информации.
 */
void PrintedPublication::printInfo() const
{
    cout << "Печатное издание: " << title << "\nISBN: " << isbn
         << "\nСтраниц: " << pages << "\nИздательство: " << publisher << "\n";
}
