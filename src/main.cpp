
#include "Book.h"
#include "Magazine.h"
#include "EBook.h"
#include "HybridBook.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <stdexcept>

using namespace std;

int main()
{
    const int MAX_PUBLICATIONS = 100;
    unique_ptr<Publication *[]> publications(new Publication *[MAX_PUBLICATIONS]);
    int publicationCount = 0;

    ifstream file("publications.txt");

    if (!file)
    {
        cerr << "Не удалось открыть publications.txt\n";
        return 1;
    }

    // Формат строки: тип|название|ISBN|страницы|издатель|автор|размер_MB|формат|номер_выпуска
    string line;

    try
    {
        while (getline(file, line))
        {
            if (line.empty() || line[0] == '#')
                continue;

            if (publicationCount >= MAX_PUBLICATIONS)
                throw runtime_error("Превышено максимальное количество изданий");

            stringstream ss(line);
            string fields[9];

            for (int i = 0; i < 9; ++i)
                if (!getline(ss, fields[i], '|'))
                    throw runtime_error("Некорректная строка в файле: " + line);

            const string type = fields[0];

            if (type == "BOOK")
            {
                publications[publicationCount++] = new Book(
                    fields[1], fields[2], stoi(fields[3]), fields[4], fields[5]);
            }
            else if (type == "MAGAZINE")
            {
                publications[publicationCount++] = new Magazine(
                    fields[1], fields[2], stoi(fields[3]), fields[4], stoi(fields[8]));
            }
            else if (type == "EBOOK")
            {
                publications[publicationCount++] = new EBook(
                    fields[1], fields[2], stod(fields[6]), fields[7]);
            }
            else if (type == "HYBRID")
            {
                publications[publicationCount++] = new HybridBook(
                    fields[1], fields[2], stoi(fields[3]), fields[4], fields[5],
                    stod(fields[6]), fields[7]);
            }
            else
            {
                throw runtime_error("Неизвестный тип: " + type);
            }
        }
    }
    catch (const exception &e)
    {
        for (int i = 0; i < publicationCount; ++i)
            delete publications[i];

        cerr << "Ошибка чтения: " << e.what() << "\n";
        return 1;
    }

    cout << "Загружено из файла: " << publicationCount << " изданий\n\n";

    for (int i = 0; i < publicationCount; ++i)
    {
        publications[i]->printInfo(); // полиморфный вызов
        cout << "-------------------------\n";
    }

    cout << "\nВсего объектов: " << Publication::getTotalCount()
         << "\nЭлектронных объектов: " << Publication::getDigitalCount() << "\n";

    const string searchISBN = "978-5-17-000001-1";
    Publication *found = Publication::findByISBN(searchISBN);

    if (found)
    {
        cout << "\nНайдено по ISBN " << searchISBN << ":\n";
        found->printInfo();
    }
    else
    {
        cout << "\nИздание с ISBN " << searchISBN << " не найдено.\n";
    }

    // Проверка копирования и присваивания HybridBook
    HybridBook original("Тестовая гибридная книга", "TEST-ISBN-1", 300,
                        "Тест-издательство", "Тестовый автор", 12.5, "PDF");

    HybridBook copy(original); // конструктор копирования

    HybridBook assigned("Временная", "TEMP", 10, "Временное", "Автор", 1.0, "EPUB");
    assigned = original; // оператор присваивания

    original = HybridBook("Изменённый оригинал", "TEST-ISBN-2", 100,
                          "Новое издательство", "Другой автор", 5.0, "EPUB");

    cout << "\nКопия после изменения оригинала (должна остаться прежней):\n";
    copy.printInfo();

    cout << "\nПрисвоенный объект:\n";
    assigned.printInfo();

    // Дружественная функция
    cout << "\nВызов дружественной функции:\n";
    printPublication(*publications[0]);

    // Освобождение памяти
    for (int i = 0; i < publicationCount; ++i)
        delete publications[i];

    return 0;
}
