#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <locale>
#include <vector>
#include <algorithm>
#include <ctime>
#include <filesystem>

void developer_information() {
    std::cout << "Мельник Дмитро ©, Усі права захищені." << std::endl;
}

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

// 10.1
void process_text_file(const std::string& input_file, const std::string& output_file) {
    std::ifstream infile(input_file);
    if (!infile.is_open()) {
        std::cerr << "Не вдалося відкрити вхідний файл." << std::endl;
        return;
    }
    
    // Зчитуємо весь файл
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }
    infile.close();

    // Знаходимо рядок автора та мови
    std::string author_line;
    std::string language_line;
    size_t start_idx = 0;
    size_t end_idx = lines.size();

    // Шукаємо рядок з інформацією про автора (зазвичай на початку)
    if (!lines.empty() && lines[0].find("Автор:") != std::string::npos) {
        author_line = lines[0];
        start_idx = 1;
        // Пропускаємо порожні рядки після автора
        while (start_idx < lines.size() && lines[start_idx].empty()) {
            start_idx++;
        }
    }

    // Шукаємо рядок з інформацією про мову (зазвичай в кінці)
    if (!lines.empty() && lines.back().find("Мова тексту:") != std::string::npos) {
        language_line = lines.back();
        end_idx = lines.size() - 1;
        // Пропускаємо порожні рядки перед мовою
        while (end_idx > start_idx && lines[end_idx - 1].empty()) {
            end_idx--;
        }
    }

    // Збираємо абзаци
    std::vector<std::string> paragraphs;
    std::string paragraph;
    
    for (size_t i = start_idx; i < end_idx; ++i) {
        if (lines[i].empty()) {
            if (!paragraph.empty()) {
                paragraphs.push_back(paragraph);
                paragraph.clear();
            }
        } else {
            if (!paragraph.empty()) {
                paragraph += "\n";
            }
            paragraph += lines[i];
        }
    }
    
    if (!paragraph.empty()) {
        paragraphs.push_back(paragraph);
    }

    // Реверсуємо абзаци
    if (paragraphs.size() > 1) {
        std::reverse(paragraphs.begin(), paragraphs.end());
    }

    // Записуємо результат
    std::ofstream outfile(output_file);
    if (!outfile.is_open()) {
        std::cerr << "Не вдалося відкрити вихідний файл." << std::endl;
        return;
    }

    // Записуємо автора
    if (!author_line.empty()) {
        outfile << author_line << "\n\n";
    } else {
        outfile << "Автор: Мельник Дмитро, KN-24, Кропивницький, 2025\n\n";
    }

    // Записуємо абзаци
    for (size_t i = 0; i < paragraphs.size(); ++i) {
        outfile << paragraphs[i];
        if (i < paragraphs.size() - 1) {
            outfile << "\n\n";
        }
    }

    // Записуємо інформацію про мову
    if (!language_line.empty()) {
        outfile << "\n\n" << language_line;
    } else {
        // Визначаємо мову тексту
        bool is_english = true;
        for (const auto& p : paragraphs) {
            if (p.find_first_of("абвгґдеєжзиіїйклмнопрстуфхцчшщьюяАБВГҐДЕЄЖЗИІЇЙКЛМНОПРСТУФХЦЧШЩЬЮЯ") != std::string::npos) {
                is_english = false;
                break;
            }
        }
        outfile << "\n\n" << "Мова тексту: " << (is_english ? "англійська" : "українська") << ".";
    }

    outfile.close();
    std::cout << "Обробка файлу завершена. Результат записано у " << output_file << std::endl;
}

// 10.2
void append_file_info(const std::string& file_path) {
    std::ifstream infile(file_path);
    if (!infile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для читання." << std::endl;
        return;
    }

    int comma_count = 0, period_count = 0;
    char ch;

    // Підрахунок кількості ком та крапок
    while (infile.get(ch)) {
        if (ch == ',') ++comma_count;
        if (ch == '.') ++period_count;
    }
    infile.close();

    // Отримання поточної дати та часу
    std::time_t now = std::time(nullptr);
    std::tm* local_time = std::localtime(&now);
    char time_buffer[100];
    std::strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", local_time);

    // Додавання інформації у файл
    std::ofstream outfile(file_path, std::ios::app);
    if (!outfile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }

    outfile << "\nКількість ком: " << comma_count << "\n";
    outfile << "Кількість крапок: " << period_count << "\n";
    outfile << "Дата і час допису: " << time_buffer << "\n";

    outfile.close();
    std::cout << "Інформацію успішно дописано у файл." << std::endl;
}

// 10.3
void append_calculation_and_binary(const std::string& file_path, double x, double y, double z, int b) {
    std::ofstream outfile(file_path, std::ios::app);
    if (!outfile.is_open()) {
        std::cerr << "Не вдалося відкрити файл для запису." << std::endl;
        return;
    }

    // Обчислення результату функції s_calculation
    double calculation_result = s_calculation(x, y, z);
    outfile << "Результат s_calculation(" << x << ", " << y << ", " << z << "): " 
            << (std::isnan(calculation_result) ? "NAN" : std::to_string(calculation_result)) << "\n";

    // Перетворення числа b у двійковий код
    outfile << "Число " << b << " у двійковому коді: " << std::bitset<32>(b) << "\n";

    outfile.close();
    std::cout << "Результати успішно дописано у файл." << std::endl;
}