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
