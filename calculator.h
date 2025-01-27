#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <memory>
#include "operation.h"

class Calculator {
private:
    std::unique_ptr<Operation> operation;
public:
    Calculator(std::unique_ptr<Operation> op);
    void setOperation(std::unique_ptr<Operation> op);
    double calculate(double a, double b);
};

#endif // CALCULATOR_H