#include "complex.hpp"

// Сложение комплексных чисел
Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

// Вычитание комплексных чисел
Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

// Умножение комплексных чисел
Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

// Деление комплексных чисел
Complex divide(Complex a, Complex b) {
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    if (denominator == 0) {
        cout << "Ошибка: Деление на ноль!" << endl;
        result.real = result.imag = 0;
        return result;
    }
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

// Вывод комплексного числа
void printComplex(Complex num) {
    if (num.imag >= 0)
        cout << num.real << " + " << num.imag << "i" << endl;
    else
        cout << num.real << " - " << abs(num.imag) << "i" << endl;
}