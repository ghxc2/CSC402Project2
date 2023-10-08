#include <vector>
#include "Employee.h"
#pragma once
using namespace std;
class myQueue {
private:
    vector<Employee> elts;
public:
    vector<Employee> & getElts();
    void Enqueue(Employee);
    Employee Dequeue();
    bool isempty();
    void printQueue();
    myQueue& operator+(const myQueue& other);
};