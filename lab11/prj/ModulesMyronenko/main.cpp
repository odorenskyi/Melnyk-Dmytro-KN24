#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <limits>
#include <windows.h>
#include <sstream>
#include "struct_type_project_3.h"

using namespace std;

// ANSI escape codes for colors
#define COLOR_RESET   "\033[0m"
#define COLOR_HEADER  "\033[1;36m"
#define COLOR_LABEL   "\033[1;33m"
#define COLOR_VALUE   "\033[1;37m"
#define COLOR_BORDER  "\033[1;34m"

void PrintDatabase(const vector<PersonRecord>& database, ostream& out) {
    bool useColors = (&out == &std::cout);

    // Кольори тільки для консолі
    const char* color_reset   = useColors ? COLOR_RESET   : "";
    const char* color_header  = useColors ? COLOR_HEADER  : "";
    const char* color_label   = useColors ? COLOR_LABEL   : "";
    const char* color_value   = useColors ? COLOR_VALUE   : "";
    const char* color_border  = useColors ? COLOR_BORDER  : "";

    // ...далі замість COLOR_* використовуйте color_*
    out << color_border << "╔══════════════════════════════════════════════════════════════════════════════╗\n";
    out << color_header << "║                        БАЗА ДАНИХ ПРАЦІВНИКІВ                              " << color_border << "║\n";
    out << "╠══════════════════════════════════════════════════════════════════════════════╣\n" << color_reset;
    int idx = 1;
    for (const auto& card : database) {
        out << color_border << "║" << color_reset << color_header << " Картка #" << idx++ << color_reset
            << string(68 - to_string(idx-1).length(), ' ') << color_border << "║\n";
        out << "╟──────────────────────────────────────────────────────────────────────────────╢\n";
        out << color_label << setw(25) << left << "  Дата створення:" << color_value
            << setw(2) << setfill('0') << card.created.day << "."
            << setw(2) << card.created.month << "."
            << setw(4) << card.created.year << setfill(' ') << color_reset << endl;
        out << color_label << setw(25) << "  Табельний номер:" << color_value << card.registrationNumber << color_reset << endl;
        out << color_label << setw(25) << "  Індифікаційний номер:" << color_value << card.identifier << color_reset << endl;
        out << color_label << setw(25) << "  ПІБ:" << color_value << card.name << color_reset << endl;
        out << color_label << setw(25) << "  Стать:" << color_value << (card.sex == 'm' ? "Чоловіча" : "Жіноча") << color_reset << endl;
        out << color_label << setw(25) << "  Вид роботи:" << color_value << (card.workType == 'f' ? "Фіксована" : "Погодинна") << color_reset << endl;
        out << color_label << setw(25) << "  Дата народження:" << color_value
            << setw(2) << setfill('0') << card.birth.day << "."
            << setw(2) << card.birth.month << "."
            << setw(4) << card.birth.year << setfill(' ') << color_reset << endl;
        out << color_label << setw(25) << "  Громадянство:" << color_value << card.nationality << color_reset << endl;
        out << color_label << setw(25) << "  Освіта:" << color_value;
        for (int i = 0; i < 4; ++i) {
            out << static_cast<int>(card.education[i]) << " (" << card.educationInstitutions[i] << ") ";
        }
        out << color_reset << endl;
        out << color_label << setw(25) << "  Попереднє місце роботи:" << color_value << card.previousWorkplace << color_reset << endl;
        out << color_label << setw(25) << "  Попередня посада:" << color_value << card.previousPosition << color_reset << endl;
        out << color_label << setw(25) << "  Стаж:" << color_value
            << card.experience.years << " р., "
            << card.experience.months << " міс., "
            << card.experience.days << " дн." << color_reset << endl;
        out << color_label << setw(25) << "  Адреса:" << color_value << card.address << color_reset << endl;
        out << color_label << setw(25) << "  Паспортні дані:" << color_value << card.passportDetails << color_reset << endl;
        out << color_label << setw(25) << "  Додаткова інформація:" << color_value << card.extraInfo << color_reset << endl;
        out << color_label << setw(25) << "  Дата звільнення:" << color_value
            << setw(2) << setfill('0') << card.terminationDate.day << "."
            << setw(2) << card.terminationDate.month << "."
            << setw(4) << card.terminationDate.year << setfill(' ') << color_reset << endl;
        out << color_label << setw(25) << "  Причина звільнення:" << color_value << card.terminationReason << color_reset << endl;
        out << color_border << "╟──────────────────────────────────────────────────────────────────────────────╢\n" << color_reset;
    }
    out << color_border << "╚══════════════════════════════════════════════════════════════════════════════╝\n" << color_reset;
}

// Допоміжна функція для зчитування дати у форматі дд.мм.рррр
bool ReadDate(Date& d) {
    std::string s;
    getline(cin, s);
    if (s.empty()) return false;
    int day = 0, month = 0, year = 0;
    char dot1 = 0, dot2 = 0;
    std::istringstream iss(s);
    iss >> day >> dot1 >> month >> dot2 >> year;
    if (iss.fail() || dot1 != '.' || dot2 != '.') return false;
    d.day = day; d.month = month; d.year = year;
    return true;
}

void AddPersonalCard(std::vector<PersonRecord>& database) {
    PersonRecord p;
    cout << "=== Додавання нового працівника ===" << endl;

    // Дата створення
    while (true) {
        cout << "Введіть дату створення (дд.мм.рррр): ";
        if (!ReadDate(p.created) || p.created.day < 1 || p.created.day > 31 || p.created.month < 1 || p.created.month > 12 || p.created.year < 1900 || p.created.year > 2100) {
            cout << "Некоректна дата! Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    // Табельний номер
    while (true) {
        cout << "Введіть табельний номер: ";
        cin >> p.registrationNumber;
        if (cin.fail() || p.registrationNumber < 0) {
            cout << "Некоректний номер! Спробуйте ще раз.\n";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    // Індифікаційний номер
    while (true) {
        cout << "Введіть індифікаційний номер: ";
        cin >> p.identifier;
        if (cin.fail() || p.identifier < 0) {
            cout << "Некоректний номер! Спробуйте ще раз.\n";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    // ПІБ
    cout << "Введіть ПІБ: ";
    getline(cin, p.name);

    // Стать
    while (true) {
        cout << "Стать (m - чоловіча, f - жіноча): ";
        cin >> p.sex;
        if (p.sex != 'm' && p.sex != 'f') {
            cout << "Некоректне значення! Введіть 'm' або 'f'.\n";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    // Вид роботи
    while (true) {
        cout << "Вид роботи (f - фіксована, h - погодинна): ";
        cin >> p.workType;
        if (p.workType != 'f' && p.workType != 'h') {
            cout << "Некоректне значення! Введіть 'f' або 'h'.\n";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    // Дата народження
    while (true) {
        cout << "Введіть дату народження (дд.мм.рррр): ";
        if (!ReadDate(p.birth) || p.birth.day < 1 || p.birth.day > 31 || p.birth.month < 1 || p.birth.month > 12 || p.birth.year < 1900 || p.birth.year > 2100) {
            cout << "Некоректна дата! Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    // Громадянство
    cout << "Введіть громадянство: ";
    getline(cin, p.nationality);

    // Освіта
    cout << "Введіть 4 рівні освіти (0-Базова середня, 1-Повна середня, 2-Професійна, 3-Неповна вища, 4-Базова вища, 5-Вища):" << endl;
    for (int i = 0; i < 4; ++i) {
        while (true) {
            cout << "  Освіта #" << (i+1) << ": ";
            string levelStr;
            getline(cin, levelStr);
            if (levelStr.empty()) {
                p.education[i] = static_cast<EducationLevel>(0);
                p.educationInstitutions[i] = "";
                break;
            }
            int level;
            try {
                level = stoi(levelStr);
            } catch (...) {
                cout << "Некоректний рівень! Введіть число від 0 до 5 або залиште порожнім.\n";
                continue;
            }
            if (level < 0 || level > 5) {
                cout << "Некоректний рівень! Введіть число від 0 до 5 або залиште порожнім.\n";
                continue;
            }
            p.education[i] = static_cast<EducationLevel>(level);
            cout << "  Заклад освіти #" << (i+1) << ": ";
            getline(cin, p.educationInstitutions[i]);
            break;
        }
    }

    // Попереднє місце роботи
    cout << "Введіть попереднє місце роботи: ";
    getline(cin, p.previousWorkplace);

    // Попередня посада
    cout << "Введіть попередню посаду: ";
    getline(cin, p.previousPosition);

    // Стаж
    while (true) {
        cout << "Введіть стаж (роки місяці дні): ";
        cin >> p.experience.years >> p.experience.months >> p.experience.days;
        if (cin.fail() || p.experience.years < 0 || p.experience.months < 0 || p.experience.months > 11 || p.experience.days < 0 || p.experience.days > 31) {
            cout << "Некоректний стаж! Спробуйте ще раз.\n";
            cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    // Адреса
    cout << "Введіть адресу: ";
    getline(cin, p.address);

    // Паспортні дані
    cout << "Введіть паспортні дані: ";
    getline(cin, p.passportDetails);

    // Додаткова інформація
    cout << "Введіть додаткову інформацію: ";
    getline(cin, p.extraInfo);

    // Дата звільнення
    while (true) {
        cout << "Введіть дату звільнення (дд.мм.рррр, якщо не звільнений - 0.0.0): ";
        if (!ReadDate(p.terminationDate) ||
            (p.terminationDate.day != 0 && (p.terminationDate.day < 1 || p.terminationDate.day > 31)) ||
            (p.terminationDate.month != 0 && (p.terminationDate.month < 1 || p.terminationDate.month > 12)) ||
            (p.terminationDate.year != 0 && (p.terminationDate.year < 1900 || p.terminationDate.year > 2100))) {
            cout << "Некоректна дата! Спробуйте ще раз.\n";
        } else {
            break;
        }
    }

    // Причина звільнення
    cout << "Введіть причину звільнення (або залиште порожнім): ";
    getline(cin, p.terminationReason);

    database.push_back(p);
    cout << "Новий запис додано!" << endl;
}
