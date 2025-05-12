#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <windows.h> // Додано для SetConsoleOutputCP та SetConsoleCP
#include "struct_type_project_3.h"

using namespace std;

// Додаємо визначення макросів кольорів, якщо потрібно
#define COLOR_RESET   "\033[0m"
#define COLOR_HEADER  "\033[1;36m"
#define COLOR_LABEL   "\033[1;33m"
#define COLOR_VALUE   "\033[1;37m"
#define COLOR_BORDER  "\033[1;34m"

void RemoveRecordByIndex(std::vector<PersonRecord>& database, std::ostream& out) {
    if (database.empty()) {
        out << "База даних порожня. Нічого видаляти.\n";
        return;
    }
    out << "Поточна база даних:\n";
    for (size_t i = 0; i < database.size(); ++i) {
        out << i + 1 << ". " << database[i].name << "\n";
    }
    out << "Введіть номер запису для видалення (1-" << database.size() << "): ";
    size_t idx;
    std::cin >> idx;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (idx < 1 || idx > database.size()) {
        out << "Невірний номер запису.\n";
        return;
    }
    database.erase(database.begin() + (idx - 1));
    out << "Запис видалено.\n";
}

void ShowMenu() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    cout << COLOR_BORDER << "\n╔══════════════════════════════════════════════╗\n";
    cout << COLOR_HEADER <<   "║                  МЕНЮ                       ║\n";
    cout << COLOR_BORDER <<   "╠══════════════════════════════════════════════╣\n";
    cout << COLOR_LABEL <<    "║ 1. Вивести всю базу на екран або у файл     ║\n";
    cout <<                  "║ 2. Додати новий запис до бази даних         ║\n";
    cout <<                  "║ 3. Пошук за прізвищем                       ║\n";
    cout <<                  "║ 4. Вилучити запис з бази даних              ║\n";
    cout <<                  "║ 0. Вихід (автоматичне збереження БД)        ║\n";
    cout << COLOR_BORDER <<   "╚══════════════════════════════════════════════╝\n";
    cout << COLOR_RESET <<    ">>> ";
}