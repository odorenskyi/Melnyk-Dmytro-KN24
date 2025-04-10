#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>
#include <windows.h>
#include "ModulesMelnyk.h"

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int choice;
    do {
        std::cout << "Оберіть дію:\n";
        std::cout << "1. Обробити текстовий файл\n";
        std::cout << "2. Додати інформацію до файлу\n";
        std::cout << "3. Обчислити значення функції та записати в двійковий файл\n";
        std::cout << "0. Вийти\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string inputFile, outputFile;
                std::cout << "Введіть ім'я вхідного файлу: ";
                std::cin >> inputFile;
                std::cout << "Введіть ім'я вихідного файлу: ";
                std::cin >> outputFile;

                process_text_file(inputFile, outputFile);
                break;
            }
            case 2: {
                std::string outputFile;
                std::cout << "Введіть ім'я файлу для додавання інформації: ";
                std::cin >> outputFile;
                append_file_info(outputFile);
                break;
            }
            case 3: {
                double x, y, z;
                int b;
                std::cout << "Введіть x, y, z: ";
                std::cin >> x >> y >> z;
                std::cout << "Введіть число b: ";
                std::cin >> b;
                std::string file_path;
                std::cout << "Введіть ім'я файлу для запису: ";
                std::cin >> file_path;
                append_calculation_and_binary(file_path, x, y, z, b);
                break;
            }
            case 0:
                std::cout << "Вихід з програми.\n";
                break;
            default:
                std::cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
