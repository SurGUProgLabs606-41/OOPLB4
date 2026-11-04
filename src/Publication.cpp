/**
 * @file Publication.cpp
 * @brief Реализация методов базового класса Publication.
 *
 * @details
 * Реализует следующие требования лабораторной работы:
 *
 * Пункт 3. Реализация виртуальной функции isDigital()
 * по умолчанию, возвращающей false.
 *
 * Пункт 4. Реализация конструктора копирования
 * и оператора присваивания.
 *
 * Пункт 5. Инициализация и изменение статических счётчиков,
 * получение количества объектов и поиск издания по ISBN.
 *
 * Пункт 8. Реализация дружественной функции printPublication().
 *
 * Дополнительно реализуется регистрация созданных объектов
 * в статическом массиве registry и удаление записей
 * при уничтожении объектов.
 */


#include "Publication.h"
#include <iostream>

using namespace std;

/** Инициализация общего счётчика объектов изданий. */
int Publication::totalCount = 0;

/** Инициализация счётчика электронных изданий. */
int Publication::digitalCount = 0;

/** Инициализация массива зарегистрированных объектов. */
Publication* Publication::registry[100] = {};

/** Инициализация количества зарегистрированных объектов. */
int Publication::registryCount = 0;

/**
 * @brief Конструктор нового издания.
 * @param title Название издания.
 * @param isbn ISBN издания.
 *
 * Сохраняет переданные данные, увеличивает общий счётчик
 * и добавляет адрес созданного объекта в массив registry.
 */
Publication::Publication(const string& title, const string& isbn)
    : title(title), isbn(isbn)
{
    ++totalCount;

    if (registryCount < 100)
        registry[registryCount++] = this;
}

/**
 * @brief Конструктор копирования.
 * @param other Исходный объект для копирования.
 *
 * Создаёт независимую копию строковых полей, увеличивает
 * общий счётчик и регистрирует новый объект.
 */
Publication::Publication(const Publication& other)
    : title(other.title), isbn(other.isbn)
{
    ++totalCount;

    if (registryCount < 100)
        registry[registryCount++] = this;
}

/**
 * @brief Оператор присваивания.
 * @param other Объект, данные которого копируются.
 * @return Ссылка на текущий объект.
 *
 * Проверяет, не выполняется ли самоприсваивание.
 * Затем копирует название и ISBN.
 */
Publication& Publication::operator=(const Publication& other)
{
    if (this != &other)
    {
        title = other.title;
        isbn = other.isbn;
    }

    return *this;
}

/**
 * @brief Деструктор базового класса.
 *
 * Находит текущий объект в массиве registry, удаляет его
 * из массива и уменьшает общий счётчик объектов.
 */
Publication::~Publication()
{
    for (int i = 0; i < registryCount; ++i)
    {
        if (registry[i] == this)
        {
            for (int j = i; j < registryCount - 1; ++j)
                registry[j] = registry[j + 1];

            registry[--registryCount] = nullptr;
            break;
        }
    }

    --totalCount;
}

/**
 * @brief Проверяет, является ли издание электронным.
 * @return false, поскольку базовое издание по умолчанию
 *         считается неэлектронным.
 */
bool Publication::isDigital() const
{
    return false;
}

/**
 * @brief Получает общее количество существующих изданий.
 * @return Значение статического счётчика totalCount.
 */
int Publication::getTotalCount()
{
    return totalCount;
}

/**
 * @brief Получает количество электронных изданий.
 * @return Значение статического счётчика digitalCount.
 */
int Publication::getDigitalCount()
{
    return digitalCount;
}

/**
 * @brief Ищет издание по его ISBN.
 * @param value ISBN, по которому выполняется поиск.
 * @return Указатель на найденное издание или nullptr,
 *         если совпадений нет.
 *
 * Последовательно проверяет зарегистрированные объекты.
 * Для получения ISBN используется виртуальный метод getISBN().
 */
Publication* Publication::findByISBN(const string& value)
{
    for (int i = 0; i < registryCount; ++i)
    {
        Publication* item = registry[i];

        if (item && item->getISBN() == value)
            return item;
    }

    return nullptr;
}

/**
 * @brief Дружественная функция вывода информации об издании.
 * @param publication Издание, информацию о котором необходимо вывести.
 *
 * Вызывает виртуальный метод printInfo(), поэтому формат вывода
 * определяется фактическим типом переданного объекта.
 */
void printPublication(const Publication& publication)
{
    publication.printInfo();
}
