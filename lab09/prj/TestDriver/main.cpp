#include <windows.h>
#include <iostream>
#include <string>
#include <cmath>

#include "ModulesMelnyk.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    // Тестування функції 9.1 (wave_height)
    double grade, waveHeight;
    std::string description;
    cout << "Тестування функції wave_height (9.1):" << endl;
    cout << "Введіть градацію (0-9): ";
    cin >> grade;
    wave_height(grade, waveHeight, description);
    cout << "Висота хвилі: " << waveHeight << ", Опис: " << description << endl;

    // Тестування функції 9.2 (count_numbers)
    int n;
    cout << "\nТестування функції count_numbers (9.2):" << endl;
    cout << "Введіть кількість чисел: ";
    cin >> n;
    count_numbers(n);

    // Тестування функції 9.3 (binary_count)
    int N;
    cout << "\nТестування функції binary_count (9.3):" << endl;
    cout << "Введіть число N: ";
    cin >> N;
    binary_count(N);

    return 0;
}
