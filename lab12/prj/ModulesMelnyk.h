#ifndef MODULESMELNYK_H_INCLUDED
#define MODULESMELNYK_H_INCLUDED

#include <cmath>

class ClassLab12_Melnyk {
private:
    float a;
    float b;

public:
    ClassLab12_Melnyk(float a, float b);
    float getA();
    float getB();
    void setA(float a);
    void setB(float b);
    float getArea();
};

ClassLab12_Melnyk::ClassLab12_Melnyk(float a, float b) : a(a), b(b) {}

float ClassLab12_Melnyk::getA() { return a; }
float ClassLab12_Melnyk::getB() { return b; }

void ClassLab12_Melnyk::setA(float a) { this->a = a; }
void ClassLab12_Melnyk::setB(float b) { this->b = b; }

float ClassLab12_Melnyk::getArea() { return static_cast<float>(M_PI) * a * b; }

#endif // MODULESMELNYK_H_INCLUDED
