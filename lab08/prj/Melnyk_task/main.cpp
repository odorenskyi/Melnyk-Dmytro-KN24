#include <iostream>
#include <windows.h>
#include <iomanip>
#include <cstdint>
#include "ModulesMelnyk.h"

using namespace std;

void developer_information() {
    cout << "Мельник Дмитро ©, Усі права захищені." << endl;
}

double logical(int a, int b){
    cout << "Результат логічного виразу: ";

    if (a + 1 <= b){
        cout << "1";
        return 1;
    }else{
        cout << "0";
        return 0;
    }
}

void numbers_in_systems(double x, double y, double z){
    union {
        int d;
        int64_t i;
    } x_conv = {x}, y_conv = {y}, z_conv = {z};

    cout << "\nЗначення змінних в десятковій та шістнадцятковій системах числення:" << endl;
    cout << "x = " << fixed << setprecision(2) << x << " (десяткова) = 0x"
         << hex << uppercase << x_conv.i << " (шістнадцяткова)" << dec << nouppercase << endl;
    cout << "y = " << fixed << setprecision(2) << y << " (десяткова) = 0x"
         << hex << uppercase << y_conv.i << " (шістнадцяткова)" << dec << nouppercase << endl;
    cout << "z = " << fixed << setprecision(2) << z << " (десяткова) = 0x"
         << hex << uppercase << z_conv.i << " (шістнадцяткова)" << dec << nouppercase << endl;

    double s = s_calculation(x, y, z);
    cout << "\n\nРезультат обчислення функції s_calculation: " << fixed << setprecision(6) << s << endl;
}

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double x, y, z;
    int a, b;

    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;
    cout << "Введіть a: ";
    cin >> a;
    cout << "Введіть b: ";
    cin >> b;

    developer_information();
    cout << "\n";
    logical(a, b);
    cout << "\n";
    numbers_in_systems(x, y, z);

    return 0;
}
