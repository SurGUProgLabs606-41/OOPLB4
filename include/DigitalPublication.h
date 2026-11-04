/**
 * @file DigitalPublication.h
 * @brief Объявление промежуточного класса DigitalPublication.
 *
 * @details
 * Класс представляет электронное библиотечное издание.
 *
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 1. Второй уровень иерархии наследования.
 * Наследуется от Publication с использованием виртуального наследования.
 *
 * Пункт 3. Переопределяет виртуальную функцию isDigital(),
 * возвращая true для электронных изданий.
 *
 * Пункт 4. Объявляет конструктор копирования
 * и оператор присваивания.
 *
 * Пункт 5. Участвует в подсчёте количества электронных объектов
 * через статический счётчик digitalCount базового класса.
 *
 * Содержит характеристики электронного издания:
 * размер файла и формат.
 */


#ifndef DIGITALPUBLICATION_H
#define DIGITALPUBLICATION_H

#include "Publication.h"

using namespace std;

/**
 * @class DigitalPublication
 * @brief Промежуточный класс электронных изданий.
 *
 * Содержит характеристики электронного издания.
 * От него наследуются классы EBook и HybridBook.
 *
 * Использует виртуальное наследование от Publication,
 * чтобы избежать дублирования базового объекта при множественном
 * наследовании в классе HybridBook.
 */
class DigitalPublication : virtual public Publication
{
protected:
    /** Размер электронного файла в мегабайтах. */
    double fileSize;

    /** Формат электронного файла, например PDF или EPUB. */
    string format;

public:
    /**
     * @brief Создаёт новое электронное издание.
     * @param title Название издания.
     * @param isbn ISBN издания.
     * @param fileSize Размер электронного файла в мегабайтах.
     * @param format Формат электронного файла.
     *
     * Инициализирует базовый класс Publication и собственные поля.
     * Увеличивает счётчик электронных изданий.
     */
    DigitalPublication(const string &title, const string &isbn,
                       double fileSize, const string &format);

    /**
     * @brief Создаёт копию электронного издания.
     * @param other Объект, данные которого копируются.
     *
     * Копирует данные Publication, размер файла и формат.
     * Увеличивает счётчик электронных изданий.
     */
    DigitalPublication(const DigitalPublication &other);

    /**
     * @brief Оператор присваивания электронного издания.
     * @param other Объект, данные которого присваиваются.
     * @return Ссылка на текущий объект.
     *
     * Выполняет проверку на самоприсваивание,
     * копирует данные базового класса и собственные поля.
     */
    DigitalPublication &operator=(const DigitalPublication &other);

    /**
     * @brief Деструктор электронного издания.
     *
     * Уменьшает счётчик электронных изданий при уничтожении объекта.
     */
    ~DigitalPublication() override;

    /**
     * @brief Возвращает размер электронного файла.
     * @return Размер файла в мегабайтах.
     */
    double getFileSize() const;

    /**
     * @brief Возвращает формат электронного файла.
     * @return Строка с форматом файла.
     */
    string getFormat() const;

    /**
     * @brief Проверяет, является ли издание электронным.
     * @return true, поскольку объект относится к электронным изданиям.
     *
     * Переопределяет виртуальный метод isDigital()
     * базового класса Publication.
     */
    bool isDigital() const override;

    /**
     * @brief Выводит информацию об электронном издании.
     *
     * Переопределяет виртуальный метод printInfo()
     * базового класса Publication.
     */
    void printInfo() const override;
};

#endif
