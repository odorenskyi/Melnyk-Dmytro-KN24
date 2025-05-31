#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <filesystem>
#include <algorithm> 
#include "ModulesMelnyk.h"

using namespace std;
namespace fs = std::filesystem;

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "╔══════════════════════════════════════════════════════╗\n";
    cout << "║  Програму створив Мельник Дмитро, КН-24              ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n\n";

    // Функція для обробки помилки шляху
    auto wrongPathError = [](const string& fileName, const string& reason) {
        ofstream testResult(fileName);
        for (int i = 0; i < 100; ++i) cout << '\a';
        testResult << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << endl;
        testResult << "Порушено вимогу: " << reason << endl;
        testResult.close();
    };

    // Перевірка шляху до main.cpp
    char exePath[MAX_PATH];
    GetModuleFileNameA(NULL, exePath, MAX_PATH);
    string pathStr = exePath;
    string requiredPath = "\\Lab12\\prj\\";
    // Додаємо перевірку без урахування регістру для різних варіантів написання шляху
    string pathStrLower = pathStr;
    string requiredPathLower = requiredPath;
    // Перетворення до нижнього регістру
    transform(pathStrLower.begin(), pathStrLower.end(), pathStrLower.begin(), ::tolower);
    transform(requiredPathLower.begin(), requiredPathLower.end(), requiredPathLower.begin(), ::tolower);
    if (pathStrLower.find(requiredPathLower) == string::npos) {
        wrongPathError("TestResults.txt", "main.cpp або виконуваний файл має бути у каталозі \\Lab12\\prj\\");
        cout << "Встановлені вимоги порушено! Див. TestResults.txt\n";
        return 0;
    }

    // --- Ввід даних користувачем та unit-тестування ---
    int testCount;
    cout << "Введіть кількість тестів: ";
    cin >> testCount;

    // Додаємо захист від некоректного вводу
    if (cin.fail() || testCount <= 0) {
        cout << "Некоректне число тестів! Натисніть Enter для завершення...";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    // Створюємо файл результатів у поточній директорії запуску
    ofstream outfile("TestResults.txt");
    if (!outfile) {
        cerr << "Не вдалося відкрити файл для запису результатів: TestResults.txt" << endl;
        cout << "Натисніть Enter для завершення...";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        return 1;
    }

    outfile << "╔════════╦════════════╦════════════╦════════════════════╦════════════════════╦════════════╗\n";
    outfile << "║ Тест   ║ a          ║ b          ║ Очікувана площа    ║ Обчислена площа    ║ Результат  ║\n";
    outfile << "╠════════╬════════════╬════════════╬════════════════════╬════════════════════╬════════════╣\n";

    for (int i = 0; i < testCount; ++i) {
        float a, b, expectedArea;
        cout << "\n=== Тест " << (i + 1) << " ===\n";
        cout << "Введіть a: ";
        cin >> a;
        cout << "Введіть b: ";
        cin >> b;
        cout << "Введіть очікувану площу: ";
        cin >> expectedArea;

        // Додаємо захист від некоректного вводу для кожного тесту
        if (cin.fail()) {
            cout << "Некоректний ввід! Натисніть Enter для завершення...";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin.get();
            return 1;
        }

        ClassLab12_Melnyk ellipse(a, b);
        float computedArea = ellipse.getArea();
        string result = (fabs(computedArea - expectedArea) < 0.0001) ? "Passed" : "FAILED";
        outfile << "║ " << setw(6) << left << (i + 1)
                << " ║ " << setw(10) << left << a
                << " ║ " << setw(10) << left << b
                << " ║ " << setw(18) << left << expectedArea
                << " ║ " << setw(18) << left << computedArea
                << " ║ " << setw(10) << left << result << " ║\n";
    }

    outfile << "╚════════╩════════════╩════════════╩════════════════════╩════════════════════╩════════════╝\n";
    outfile.close();

    cout << "\n╔══════════════════════════════════════════════════════╗\n";
    cout << "║ Результати тестів збережено у файл TestResults.txt   ║\n";
    cout << "╚══════════════════════════════════════════════════════╝\n";

    // Явна пауза для користувача (Enter)
    cout << "Натисніть Enter для завершення...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();

    return 0;
}
