#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <windows.h>

#include "ModulesMelnyk.h"
#include "ModulesZhukovsky.h"
#include "ModulesMyronenko.h"


using namespace std;

// void ShowMenu();

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    vector<PersonRecord> database;
    int choice;

    do {
        ShowMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                cout << "Вивести на екран (1) чи у файл (2)? ";
                int outChoice;
                cin >> outChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (outChoice == 1) {
                    PrintDatabase(database, cout);
                } else if (outChoice == 2) {
                    string filename;
                    cout << "Введіть ім'я файлу: ";
                    getline(cin, filename);
                    ofstream fout(filename);
                    if (fout.is_open()) {
                        PrintDatabase(database, fout);
                        fout.close();
                        cout << "Дані збережено у файл." << endl;
                    } else {
                        cout << "Не вдалося відкрити файл для запису." << endl;
                    }
                } else {
                    cout << "Невірний вибір." << endl;
                }
                break;
            }
            case 2:
                AddPersonalCard(database);
                break;
            case 3: {
                cout << "Введіть прізвище для пошуку: ";
                string surname;
                getline(cin, surname);
                SearchBySurname(database, surname, cout);
                break;
            }
            case 4:
                RemoveRecordByIndex(database, cout);
                break;
            case 0:
                SaveDatabaseToFile(database, "database.txt");
                cout << "Вихід з програми." << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
                break;
        }
    } while (choice != 0);

    return 0;
}
