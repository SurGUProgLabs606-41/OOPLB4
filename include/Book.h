/**
 * @file Book.h
 * @brief Объявление класса Book — обычной книги.
 *
 * @details
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 1. Третий уровень иерархии наследования:
 * Publication -> PrintedPublication -> Book.
 *
 * Пункт 3. Переопределяет виртуальные методы базового класса
 * для получения названия, ISBN и вывода информации.
 *
 * Пункт 4. Объявляет конструктор копирования
 * и оператор присваивания.
 *
 * Дополнительно содержит характеристику книги — автора.
 * От PrintedPublication - title и isbn. Виртуальные методы getTitle(), getISBN(), printInfo()
 */


#ifndef BOOK_H
#define BOOK_H

#include "PrintedPublication.h"

using namespace std;

/**
 * @class Book
 * @brief Класс печатной книги.
 *
 * Представляет обычную печатную книгу и содержит информацию
 * об авторе, количестве страниц и издательстве.
 *
 * Является производным классом PrintedPublication.
 */
class Book : public PrintedPublication
{
protected:
    /** Имя автора книги. */
    string author;

public:
    /**
     * @brief Создаёт новую книгу.
     * @param title Название книги.
     * @param isbn ISBN книги.
     * @param pages Количество страниц.
     * @param publisher Название издательства.
     * @param author Имя автора книги.
     *
     * Инициализирует базовые классы и поле автора.
     */
    Book(const string& title, const string& isbn, int pages,
         const string& publisher, const string& author);

    /**
     * @brief Создаёт копию книги.
     * @param other Книга, данные которой копируются.
     *
     * Копирует характеристики базовых классов
     * и имя автора.
     */
    Book(const Book& other);

    /**
     * @brief Оператор присваивания книги.
     * @param other Книга, данные которой присваиваются.
     * @return Ссылка на текущий объект.
     *
     * Копирует характеристики печатного издания
     * и имя автора.
     */
    Book& operator=(const Book& other);

    /**
     * @brief Виртуальный деструктор книги.
     *
     * Используется стандартный деструктор,
     * поскольку класс не управляет динамическими ресурсами.
     */
    ~Book() override = default;

    /**
     * @brief Возвращает имя автора книги.
     * @return Имя автора.
     */
    string getAuthor() const;

    /**
     * @brief Возвращает название книги.
     * @return Название книги.
     *
     * Реализует чисто виртуальный метод Publication.
     */
    string getTitle() const override;

    /**
     * @brief Возвращает ISBN книги.
     * @return ISBN книги.
     *
     * Реализует чисто виртуальный метод Publication.
     */
    string getISBN() const override;

    /**
     * @brief Выводит полную информацию о книге.
     *
     * Переопределяет виртуальный метод printInfo()
     * и выводит название, ISBN, автора, количество страниц
     * и издательство.
     */
    void printInfo() const override;
};

#endif
