#include "operation_factory.h"
#include "operation.h"
#include <stdexcept>

std::unique_ptr<Operation> OperationFactory::createOperation(char type) {
    switch (type) {
        case '+': return std::make_unique<AddOperation>();
        case '-': return std::make_unique<SubtractOperation>();
        case '*': return std::make_unique<MultiplyOperation>();
        case '/': return std::make_unique<DivideOperation>();
        default: throw std::invalid_argument("Unknown operation type");
    }
}