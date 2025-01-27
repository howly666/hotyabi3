#include "calculator.h"

Calculator::Calculator(std::unique_ptr<Operation> op) : operation(std::move(op)) {}

void Calculator::setOperation(std::unique_ptr<Operation> op) {
    operation = std::move(op);
}

double Calculator::calculate(double a, double b) {
    return operation->execute(a, b);
}