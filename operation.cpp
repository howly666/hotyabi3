#include "operation.h"
#include <stdexcept>

double AddOperation::execute(double a, double b) {
    return a + b;
}

double SubtractOperation::execute(double a, double b) {
    return a - b;
}

double MultiplyOperation::execute(double a, double b) {
    return a * b;
}

double DivideOperation::execute(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero!");
    }
    return a / b;
}