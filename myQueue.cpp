#include "myQueue.h"
#include "iostream"

using namespace std;
void myQueue::Enqueue(Employee employee) {
    elts.push_back(employee);
}

Employee myQueue::Dequeue() {
    Employee employee = elts.at(0);
    elts.erase(elts.begin());
    return employee;
}

vector<Employee> &myQueue::getElts() {
    return elts;
}

bool myQueue::isempty() {
    return elts.empty();
}

void myQueue::printQueue() {
    for (auto i = elts.begin(); i < elts.end(); i++){
        cout << *i << "\n\n";
    }
}

myQueue &myQueue::operator+(const myQueue &other) {
    for (auto i = other.elts.begin(); i < other.elts.end(); i++){
        Enqueue(*i);
    }
    return *this;
}