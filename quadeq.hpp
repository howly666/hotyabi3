#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <string>
using namespace std;

// Прототипы функций
void solveQuadraticEquation(double a, double b, double c);
bool parseQuadraticEquation(const string& equation, double& a, double& b, double& c);

#endif