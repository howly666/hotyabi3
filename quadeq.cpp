#include "quadeq.hpp"
#include "complex.hpp"
#include <cmath>
#include <regex>

// Решение квадратного уравнения
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

// Парсинг квадратного уравнения из строки
bool parseQuadraticEquation(const string& equation, double& a, double& b, double& c) {
    // Регулярное выражение для поиска коэффициентов
    regex pattern("([+-]?\\d*\\.?\\d*)x\\^2|([+-]?\\d*\\.?\\d*)x|([+-]?\\d*\\.?\\d+)");
    smatch matches;
    string str = equation;
    a = b = c = 0; // Инициализация коэффициентов

    // Поиск всех совпадений
    while (regex_search(str, matches, pattern)) {
        string term = matches[0];
        if (term.find("x^2") != string::npos) {
            // Коэффициент при x^2
            string coeff = term.substr(0, term.find("x^2"));
            a = coeff.empty() || coeff == "+" ? 1 : coeff == "-" ? -1 : stod(coeff);
        } else if (term.find("x") != string::npos) {
            // Коэффициент при x
            string coeff = term.substr(0, term.find("x"));
            b = coeff.empty() || coeff == "+" ? 1 : coeff == "-" ? -1 : stod(coeff);
        } else {
            // Свободный член
            c = stod(term);
        }
        str = matches.suffix().str();
    }
    return true;
}