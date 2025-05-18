#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <windows.h>
#include <sstream>
#include <algorithm>
#include "ModulesMelnyk.h"

using namespace std;

// Додайте визначення кольорів, якщо потрібно
#define COLOR_BORDER ""
#define COLOR_HEADER ""
#define COLOR_LABEL ""
#define COLOR_RESET ""

void SearchBySurname(const std::vector<PersonRecord>& database, const std::string& surname, std::ostream& out) {
    std::vector<PersonRecord> found;
    for (const auto& p : database) {
        // Витягуємо прізвище (перше слово у ПІБ)
        std::istringstream iss(p.name);
        std::string lastName;
        iss >> lastName;
        if (!lastName.empty() && lastName == surname) {
            found.push_back(p);
        }
    }
    if (found.empty()) {
        out << "Записів з прізвищем \"" << surname << "\" не знайдено.\n";
    } else {
        PrintDatabase(found, out);
    }
}

void SaveDatabaseToFile(const std::vector<PersonRecord>& database, const std::string& filename) {
    std::ofstream fout(filename);
    if (fout.is_open()) {
        PrintDatabase(database, fout);
        fout.close();
    }
}
