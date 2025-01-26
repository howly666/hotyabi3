#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

// Структура для комплексных чисел
struct Complex {
    double real;
    double imag;
};

// Прототипы функций
Complex add(Complex a, Complex b);
Complex subtract(Complex a, Complex b);
Complex multiply(Complex a, Complex b);
Complex divide(Complex a, Complex b);
void printComplex(Complex num);

#endif