#include <iostream>
#include <memory>
#include "calculator.h"
#include "operation_factory.h"
#include "input_utils.h"

int main() {
    // Ввод чисел и операции
    double a = inputNumber("Enter first number: ");
    char operationType = chooseOperation();
    double b = inputNumber("Enter second number: ");

    // Создание калькулятора с выбранной операцией
    Calculator calculator(OperationFactory::createOperation(operationType));

    // Выполнение вычисления
    try {
        double result = calculator.calculate(a, b);
        std::cout << "Result: " << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}