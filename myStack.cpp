#include "myStack.h"
#include <iostream>
bool myStack::isempty() {
    return elts.empty();
}

vector<Employee> &myStack::getElts() {
    return elts;
}

Employee myStack::Pop() {
    Employee employee = elts.at(elts.size() - 1);
    elts.erase(elts.end());
    return employee;
}

void myStack::Push(Employee employee) {
    elts.push_back(employee);
}

void myStack::printStack() {
    for (auto i = elts.end() - 1; i >= elts.begin(); i--){
        cout << *i << "\n\n";
    }
}

myStack &myStack::operator+(const myStack &other) {
    for (auto i = other.elts.end() - 1; i >= other.elts.begin(); i--){
        Push(*i);
    }
    return *this;
}