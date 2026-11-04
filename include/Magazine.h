/**
 * @file Magazine.h
 * @brief Объявление класса Magazine — журнала.
 *
 * @details
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 1. Третий уровень иерархии наследования:
 * Publication -> PrintedPublication -> Magazine.
 *
 * Пункт 3. Переопределяет виртуальные методы получения названия,
 * ISBN и вывода информации.
 *
 * Пункт 4. Объявляет конструктор копирования
 * и оператор присваивания.
 *
 * Дополнительно содержит характеристику журнала — номер выпуска.
 */

#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "PrintedPublication.h"

using namespace std;

/**
 * @class Magazine
 * @brief Класс печатного журнала.
 *
 * Представляет печатный журнал и содержит информацию
 * о его номере выпуска, количестве страниц и издательстве.
 *
 * Является производным классом PrintedPublication.
 */
class Magazine : public PrintedPublication
{
private:
    /** Номер выпуска журнала. */
    int issueNumber;

public:
    /**
     * @brief Создаёт новый журнал.
     * @param title Название журнала.
     * @param isbn ISBN журнала.
     * @param pages Количество страниц.
     * @param publisher Название издательства.
     * @param issueNumber Номер выпуска журнала.
     *
     * Инициализирует базовые классы и номер выпуска.
     */
    Magazine(const string &title, const string &isbn, int pages,
            const string &publisher, int issueNumber);

    /**
     * @brief Создаёт копию журнала.
     * @param other Журнал, данные которого копируются.
     *
     * Копирует характеристики базовых классов
     * и номер выпуска.
     */
    Magazine(const Magazine &other);

    /**
     * @brief Оператор присваивания журнала.
     * @param other Журнал, данные которого присваиваются.
     * @return Ссылка на текущий объект.
     *
     * Копирует характеристики печатного издания
     * и номер выпуска.
     */
    Magazine &operator=(const Magazine &other);

    /**
     * @brief Виртуальный деструктор журнала.
     *
     * Используется стандартная реализация деструктора,
     * поскольку класс не управляет динамическими ресурсами.
     */
    ~Magazine() override = default;

    /**
     * @brief Возвращает название журнала.
     * @return Название журнала.
     *
     * Реализует чисто виртуальный метод Publication.
     */
    string getTitle() const override;

    /**
     * @brief Возвращает ISBN журнала.
     * @return ISBN журнала.
     *
     * Реализует чисто виртуальный метод Publication.
     */
    string getISBN() const override;

    /**
     * @brief Выводит полную информацию о журнале.
     *
     * Переопределяет виртуальный метод printInfo()
     * и выводит название, ISBN, номер выпуска,
     * количество страниц и издательство.
     */
    void printInfo() const override;
};

#endif
