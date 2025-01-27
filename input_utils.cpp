#include "input_utils.h"
#include <iostream>
#include <limits>

double inputNumber(const std::string& prompt) {
    double number;
    while (true) {
        std::cout << prompt;
        if (std::cin >> number) {
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
    return number;
}

char chooseOperation() {
    char operation;
    while (true) {
        std::cout << "Choose operation (+, -, *, /): ";
        std::cin >> operation;
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            break;
        } else {
            std::cout << "Invalid operation. Please try again.\n";
        }
    }
    return operation;
}