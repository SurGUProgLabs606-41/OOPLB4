/**
 * @file HybridBook.h
 * @brief Объявление класса HybridBook — гибридной книги.
 *
 * @details
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 1. Третий уровень иерархии наследования.
 *
 * Пункт 3. Переопределяет виртуальные методы базового класса.
 *
 * Пункт 4. Объявляет конструктор копирования
 * и оператор присваивания.
 *
 * Пункт 7. Демонстрирует множественное наследование
 * от классов Book и DigitalPublication.
 *
 * Использует виртуальное наследование через родительские классы,
 * поэтому содержит только одну общую базовую часть Publication.
 *
 * Объединяет характеристики печатной и электронной книги.
 */

#ifndef HYBRIDBOOK_H
#define HYBRIDBOOK_H

#include "Book.h"
#include "DigitalPublication.h"

using namespace std;

/**
 * @class HybridBook
 * @brief Класс гибридной книги.
 *
 * @details
 * Гибридная книга содержит характеристики обычной книги:
 * автора, количество страниц и издательство,
 * а также характеристики электронного издания:
 * размер файла и формат.
 *
 * Наследуется от Book и DigitalPublication.
 */
class HybridBook : public Book, public DigitalPublication
{
public:
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
     * а также части Book и DigitalPublication.
     */
    HybridBook(const string &title, const string &isbn, int pages,
              const string &publisher, const string &author,
              double fileSize, const string &format);

    /**
     * @brief Конструктор копирования.
     *
     * @param other Объект гибридной книги, который копируется.
     *
     * @details
     * Создает новый объект на основе существующего,
     * копируя характеристики печатного и электронного издания.
     */
    HybridBook(const HybridBook &other);

    /**
     * @brief Оператор присваивания.
     *
     * @param other Объект, данные которого присваиваются.
     * @return Ссылка на текущий объект.
     *
     * @details
     * Проверяет самоприсваивание и копирует характеристики
     * обеих родительских частей.
     */
    HybridBook &operator=(const HybridBook &other);

    /**
     * @brief Виртуальный деструктор.
     *
     * @details
     * Обеспечивает корректное уничтожение гибридной книги
     * при удалении через указатель на базовый класс.
     */
    ~HybridBook() override = default;

    /**
     * @brief Получает название гибридной книги.
     *
     * @return Название книги.
     *
     * @details Переопределяет виртуальный метод Publication.
     */
    string getTitle() const override;

    /**
     * @brief Получает ISBN гибридной книги.
     *
     * @return Международный стандартный номер книги.
     *
     * @details Переопределяет виртуальный метод Publication.
     */
    string getISBN() const override;

    /**
     * @brief Проверяет, является ли издание электронным.
     *
     * @return true, поскольку гибридная книга содержит электронную версию.
     *
     * @details Переопределяет виртуальный метод Publication.
     */
    bool isDigital() const override;

    /**
     * @brief Выводит информацию о гибридной книге.
     *
     * @details
     * Выводит название, ISBN, автора, количество страниц,
     * издательство, размер файла и формат электронного издания.
     *
     * Переопределяет виртуальный метод Publication.
     */
    void printInfo() const override;
};

#endif
