/**
 * @file EBook.h
 * @brief Объявление класса EBook — электронной книги.
 *
 * @details
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 1. Третий уровень иерархии наследования:
 * Publication -> DigitalPublication -> EBook.
 *
 * Пункт 3. Переопределяет виртуальные методы базового класса
 * для получения названия, ISBN и вывода информации.
 *
 * Пункт 4. Объявляет конструктор копирования
 * и оператор присваивания.
 */


#ifndef EBOOK_H
#define EBOOK_H

#include "DigitalPublication.h"

using namespace std;

/**
 * @class EBook
 * @brief Класс электронной книги.
 *
 * Представляет электронную книгу и использует характеристики
 * электронного издания: размер файла и формат.
 *
 * Является производным классом DigitalPublication.
 */
class EBook : public DigitalPublication
{
public:
    /**
     * @brief Создаёт новую электронную книгу.
     * @param title Название книги.
     * @param isbn ISBN книги.
     * @param fileSize Размер электронного файла в мегабайтах.
     * @param format Формат электронного файла.
     *
     * Инициализирует базовые классы Publication
     * и DigitalPublication.
     */
    EBook(const string &title, const string &isbn,
          double fileSize, const string &format);

    /**
     * @brief Создаёт копию электронной книги.
     * @param other Электронная книга, данные которой копируются.
     *
     * Копирует характеристики базовых классов.
     */
    EBook(const EBook &other);

    /**
     * @brief Оператор присваивания электронной книги.
     * @param other Электронная книга, данные которой присваиваются.
     * @return Ссылка на текущий объект.
     *
     * Копирует характеристики DigitalPublication
     * и проверяет самоприсваивание.
     */
    EBook &operator=(const EBook &other);

    /**
     * @brief Виртуальный деструктор электронной книги.
     *
     * Используется стандартная реализация деструктора,
     * поскольку класс не управляет динамическими ресурсами.
     */
    ~EBook() override = default;

    /**
     * @brief Возвращает название электронной книги.
     * @return Название книги.
     *
     * Реализует чисто виртуальный метод Publication.
     */
    string getTitle() const override;

    /**
     * @brief Возвращает ISBN электронной книги.
     * @return ISBN книги.
     *
     * Реализует чисто виртуальный метод Publication.
     */
    string getISBN() const override;

    /**
     * @brief Выводит полную информацию об электронной книге.
     *
     * Переопределяет виртуальный метод printInfo()
     * и выводит название, ISBN, размер файла и формат.
     */
    void printInfo() const override;
};

#endif
