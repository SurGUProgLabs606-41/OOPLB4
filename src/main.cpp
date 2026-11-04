#include "Book.h"
#include "Magazine.h"
#include "EBook.h"
#include "HybridBook.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>
#include <stdexcept>

int main() {
    std::vector<std::unique_ptr<Publication>> publications;
    std::ifstream file("publications.txt");

    if (!file) {
        std::cerr << "Не удалось открыть publications.txt\n";
        return 1;
    }

    // Формат строки: тип|название|ISBN|страницы|издатель|автор|размер_MB|формат|номер_выпуска
    std::string line;
    try {
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#') continue;
            std::stringstream ss(line);
            std::string fields[9];
            for (int i = 0; i < 9; ++i)
                if (!std::getline(ss, fields[i], '|'))
                    throw std::runtime_error("Некорректная строка в файле: " + line);

            const std::string type = fields[0];
            if (type == "BOOK") {
                publications.push_back(std::make_unique<Book>(
                    fields[1], fields[2], std::stoi(fields[3]), fields[4], fields[5]));
            } else if (type == "MAGAZINE") {
                publications.push_back(std::make_unique<Magazine>(
                    fields[1], fields[2], std::stoi(fields[3]), fields[4], std::stoi(fields[8])));
            } else if (type == "EBOOK") {
                publications.push_back(std::make_unique<EBook>(
                    fields[1], fields[2], std::stod(fields[6]), fields[7]));
            } else if (type == "HYBRID") {
                publications.push_back(std::make_unique<HybridBook>(
                    fields[1], fields[2], std::stoi(fields[3]), fields[4], fields[5],
                    std::stod(fields[6]), fields[7]));
            } else {
                throw std::runtime_error("Неизвестный тип: " + type);
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "Ошибка чтения: " << e.what() << "\n";
        return 1;
    }

    std::cout << "Загружено из файла: " << publications.size() << " изданий\n\n";
    for (const auto& item : publications) {
        item->printInfo(); // полиморфный вызов
        std::cout << "-------------------------\n";
    }

    std::cout << "\nВсего объектов: " << Publication::getTotalCount()
              << "\nЭлектронных объектов: " << Publication::getDigitalCount() << "\n";

    const std::string searchISBN = "978-5-17-000001-1";
    Publication* found = Publication::findByISBN(searchISBN);
    if (found) {
        std::cout << "\nНайдено по ISBN " << searchISBN << ":\n";
        found->printInfo();
    } else {
        std::cout << "\nИздание с ISBN " << searchISBN << " не найдено.\n";
    }

    // Проверка копирования и присваивания HybridBook
    HybridBook original("Тестовая гибридная книга", "TEST-ISBN-1", 300,
                        "Тест-издательство", "Тестовый автор", 12.5, "PDF");
    HybridBook copy(original); // конструктор копирования
    HybridBook assigned("Временная", "TEMP", 10, "Временное", "Автор", 1.0, "EPUB");
    assigned = original; // оператор присваивания

    original = HybridBook("Изменённый оригинал", "TEST-ISBN-2", 100,
                          "Новое издательство", "Другой автор", 5.0, "EPUB");

    std::cout << "\nКопия после изменения оригинала (должна остаться прежней):\n";
    copy.printInfo();
    std::cout << "\nПрисвоенный объект:\n";
    assigned.printInfo();

    // Дружественная функция
    std::cout << "\nВызов дружественной функции:\n";
    printPublication(*publications.front());

    return 0;
}
