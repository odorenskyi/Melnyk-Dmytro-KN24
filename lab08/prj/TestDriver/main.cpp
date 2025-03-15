#include <iostream>
#include <windows.h>
#include "ModulesMelnyk.h"

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double x, y, z;

    cout << "Введіть x" << endl;
    cin >> x;
    cout << "Введіть y" << endl;
    cin >> y;
    cout << "Введіть z" << endl;
    cin >> z;

    double Result = s_calculation(x, y ,z);

    cout << "Відповідь: " << Result;
}
