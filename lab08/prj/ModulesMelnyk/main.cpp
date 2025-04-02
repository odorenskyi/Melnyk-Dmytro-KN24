#include <iostream>
#include <cmath>

// Функція для обчислення значення математичного виразу за заданими параметрами
double s_calculation (double x, double y, double z){

const double Pi = 3.141592653589793238; // Константа Пі з високою точністю

    if(z == 0){ // Перевірка на ділення на нуль
        return NAN;
    };

    if(sin(z) == 0 || fabs(sin(z)) < 1e-10){ // Перевірка на логарифм від нуля або дуже малого числа
        return NAN;
    }

    double sin_value = sin(z);
    double first = log(fabs(sin_value)); // Обчислення логарифма від модуля синуса

    double y_plus_z_squared = pow(y + z, 2); // Обчислення квадрата суми y та z
    double x_fifth = pow(x, 5); // Обчислення x у п'ятому степені
    double diff = y_plus_z_squared - x_fifth; // Різниця для підкореневого виразу


    if(diff < 0 && fabs(diff) > x_fifth) { // Перевірка на коректність значення під коренем
        return NAN;
    }

    double top = 0.5 * pow(x, 2) - sqrt(fabs(diff)); // Обчислення чисельника дробу
    double bottom = 10 * Pi * pow(z, 4); // Обчислення знаменника дробу

    double result = first + top / bottom; // Обчислення кінцевого результату

    return result;
}
    //лаб 9
    // 9.1
void wave_height (double grade, double& wave_height, std::string& Desсription){

    if (grade < 0 || grade > 9) { // Перевірка на допустимість значення grade
        Desсription = "Invalid grade value. It should be between 0 and 10.";
        wave_height = 0; // Присвоєння NaN у випадку недопустимого значення
        return;
    }

    if (grade == 0) {
        wave_height = 0;
        Desсription = "Calm-Glassy";
    } else if (grade == 1) {
        wave_height = 0.1;
        Desсription = "calm-rippled";
    } else if (grade == 2) {
        wave_height = 0.5;
        Desсription = "Smooth-wavelet";
    } else if (grade == 3) {
        wave_height = 1.25;
        Desсription = "Slight";
    } else if (grade == 4) {
        wave_height = 2.5;
        Desсription = "Moderate";
    } else if (grade == 5) {
        wave_height = 4.0;
        Desсription = "rough";
    } else if (grade == 6) {
        wave_height = 6.0;
        Desсription = "Very rough";
    } else if (grade == 7) {
        wave_height = 9.0;
        Desсription = "High";
    } else if (grade == 8) {
        wave_height = 12.0;
        Desсription = "Very high";
    } else if (grade == 9) {
        wave_height = 15.0;
        Desсription = "Phenomenal";
    }
}

// 9.2
void count_numbers(int n) {
    int count_zero = 0; // Лічильник чисел, рівних нулю
    int count_in_range = 0; // Лічильник чисел у діапазоні [5, 1024]

    for (int i = 0; i < n; ++i) {
        int num;
        std::cout << "Введіть число " << i + 1 << ": ";
        std::cin >> num;

        if (num == 0) {
            ++count_zero; // Збільшення лічильника для чисел, рівних нулю
        }
        if (num >= 5 && num <= 1024) {
            ++count_in_range; // Збільшення лічильника для чисел у діапазоні [5, 1024]
        }
    }

    std::cout << "Кількість чисел, рівних нулю: " << count_zero << std::endl;
    std::cout << "Кількість чисел у діапазоні [5, 1024]: " << count_in_range << std::endl;
}

// 9.3
#include <iostream>
#include <bitset>

void binary_count(int N) {
    if (N < 0 || N > 70700) {
        std::cout << "Неприпустиме значення. N повинно бути в діапазоні від 0 до 70700." << std::endl;
        return;
    }

    int bit_D1 = (N >> 1) & 1; // Отримання значення біта D1
    std::bitset<17> binary(N); // 17 біт достатньо для 70700
    int count = bit_D1 ? (17 - binary.count()) : binary.count(); // Тернарний оператор

    std::cout << "Бінарне представлення числа N: " << binary << std::endl;
    std::cout << "Біт D1 дорівнює " << bit_D1 << ". "
              << (bit_D1 ? "Кількість нулів: " : "Кількість одиниць: ")
              << count << std::endl;
}

// 9.4
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
                if (std::isnan(result)) {
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
