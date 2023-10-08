
#include <string>
#include <vector>
#include "Employee.h"
#pragma once
using namespace std;
class myStack {
private:
    vector<Employee> elts;
public:
    vector<Employee> & getElts();
    void Push(Employee);
    Employee Pop();
    bool isempty();
    void printStack();
    myStack & operator+(const myStack & other);
};
