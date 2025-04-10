#ifndef MODULESMELNYK_H_INCLUDED
#define MODULESMELNYK_H_INCLUDED

#include <string>
#include <iostream>

// Обчислення значення функції
double s_calculation(double x, double y, double z);

// Інформація про розробника
void developer_information();

// Лабораторна робота 9
void wave_height(double grade, double& wave_height, std::string& Description); // 9.1
void count_numbers(int n); // 9.2
void binary_count(int N); // 9.3
void task_9_4(); // 9.4

// Лабораторна робота 10
void process_text_file(const std::string& input_file, const std::string& output_file); // 10.1
void append_file_info(const std::string& file_path); // 10.2
void append_calculation_and_binary(const std::string& file_path, double x, double y, double z, int b); // 10.3

#endif // MODULESMELNYK_H_INCLUDED
