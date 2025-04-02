#include <iostream>
#include <cmath>
#include <windows.h>
#include "ModulesMelnyk.h"

using namespace std;
void task_9_4() {
    char choice;
    do {
        std::cout << "Введіть символ ('q', 'e', 'r', 't'): ";
        std::cin >> choice;

        switch (choice) {
            case 'q': {
                double x, y, z;
                std::cout << "Введіть x, y, z: ";
                std::cin >> x >> y >> z;
                double result = s_calculation(x, y, z);
                if (std::isnan(result)) { // Використання std::isnan
                    std::cout << "Помилка обчислення." << std::endl;
                } else {
                    std::cout << "Результат: " << result << std::endl;
                }
                break;
            }
            case 'e': {
                double grade, waveHeight;
                std::string description;
                std::cout << "Введіть градацію (0-9): ";
                std::cin >> grade;
                wave_height(grade, waveHeight, description);
                std::cout << "Висота хвилі: " << waveHeight << ", Опис: " << description << std::endl;
                break;
            }
            case 'r': {
                int n;
                std::cout << "Введіть кількість чисел: ";
                std::cin >> n;
                count_numbers(n);
                break;
            }
            case 't': {
                int N;
                std::cout << "Введіть число N: ";
                std::cin >> N;
                binary_count(N);
                break;
            }
            default:
                std::cout << "Невірний символ. Спробуйте ще раз." << std::endl;
                break;
        }

        char exitChoice;
        std::cout << "Бажаєте вийти? (y/n): ";
        std::cin >> exitChoice;
        if (exitChoice == 'y' || exitChoice == 'Y') {
            break;
        }
    } while (true);
}


int main()
{
    SetConsoleOutputCP(65001); // Встановлення кодування виводу
    SetConsoleCP(65001); // Встановлення кодування вводу

    developer_information(); // Виведення інформації про розробника

    // Виклик функції для тестування
    task_9_4();

    return 0;
}

