
#ifndef OPERATION_H
#define OPERATION_H

class Operation {
public:
    virtual double execute(double a, double b) = 0;
    virtual ~Operation() = default;
};

class AddOperation : public Operation {
public:
    double execute(double a, double b) override;
};

class SubtractOperation : public Operation {
public:
    double execute(double a, double b) override;
};

class MultiplyOperation : public Operation {
public:
    double execute(double a, double b) override;
};

class DivideOperation : public Operation {
public:
    double execute(double a, double b) override;
};

#endif // OPERATION_H