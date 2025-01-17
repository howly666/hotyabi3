#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    double real; 
    double imag; 
};

Complex add(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

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

void printComplex(Complex num) {
    if (num.imag >= 0)
        cout << num.real << " + " << num.imag << "i" << endl;
    else
        cout << num.real << " - " << abs(num.imag) << "i" << endl;
}

void solveQuadraticEquation(double a, double b, double c) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Корни уравнения: " << root1 << " и " << root2 << endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "Уравнение имеет один корень: " << root << endl;
    } else {
        Complex root1, root2;
        root1.real = -b / (2 * a);
        root1.imag = sqrt(-discriminant) / (2 * a);
        root2.real = root1.real;
        root2.imag = -root1.imag;
        cout << "Корни уравнения: ";
        printComplex(root1);
        cout << " и ";
        printComplex(root2);
    }
}

int main() {
    int choice;
    cout << "Выберите операцию:\n";
    cout << "1. Калькулятор комплексных чисел\n";
    cout << "2. Решение квадратного уравнения\n";
    cin >> choice;

    if (choice == 1) {
        Complex num1, num2, result;
        char operation;

        cout << "Введите действительную и мнимую часть первого числа: ";
        cin >> num1.real >> num1.imag;

        cout << "Введите операцию (+, -, *, /): ";
        cin >> operation;

        cout << "Введите действительную и мнимую часть второго числа: ";
        cin >> num2.real >> num2.imag;

        switch (operation) {
            case '+':
                result = add(num1, num2);
                break;
            case '-':
                result = subtract(num1, num2);
                break;
            case '*':
                result = multiply(num1, num2);
                break;
            case '/':
                result = divide(num1, num2);
                break;
            default:
                cout << "Ошибка: Неверная операция!" << endl;
                return 1;
        }

        cout << "Результат: ";
        printComplex(result);
    } else if (choice == 2) {
        double a, b, c;
        cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
        cin >> a >> b >> c;

        if (a == 0) {
            cout << "Ошибка: Это не квадратное уравнение (a = 0)!" << endl;
            return 1;
        }

        solveQuadraticEquation(a, b, c);
    } else {
        cout << "Ошибка: Неверный выбор!" << endl;
    }

    return 0;


}