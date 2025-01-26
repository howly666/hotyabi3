#include <iostream>
#include "complex.hpp"
#include "quadeq.hpp"

using namespace std;

int main() {
    int choice;
    cout << "Выберите операцию:\n";
    cout << "1. Калькулятор комплексных чисел\n";
    cout << "2. Решение квадратного уравнения\n";
    cin >> choice;
    cin.ignore(); // Игнорируем оставшийся символ новой строки

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
        string equation;
        double a, b, c;

        cout << "Введите квадратное уравнение в формате ax^2 + bx + c: ";
        getline(cin, equation);

        if (!parseQuadraticEquation(equation, a, b, c)) {
            cout << "Ошибка: Неверный формат уравнения!" << endl;
            return 1;
        }

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