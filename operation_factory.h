#ifndef OPERATION_FACTORY_H
#define OPERATION_FACTORY_H

#include <memory>
#include "operation.h"

class OperationFactory {
public:
    static std::unique_ptr<Operation> createOperation(char type);
};

#endif // OPERATION_FACTORY_H