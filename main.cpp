#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "myStack.h"
#include "myQueue.h"
#include "ostream"
using namespace std;

ostream& operator<<(ostream &stream, Employee &employee) {
    string S = employee.getLastName() + " " + employee.getFirstName() + " " + employee.getSocSecNum() + " " + employee.getDeptNum() + " " + to_string(employee.getWage());
    stream << S;
    return stream;
}

int main() {
    // Create Stacks
    myStack S1, S2;
    myQueue Q1, Q2;

    // Reading File Name Input
    cout << "Please enter a path for file #1:";
    string name1, name2;
    cin >> name1;
    cout << "Please enter a path for file #2:";
    cin >> name2;

    // Read File Input
    ifstream inf(name1);
    if (!inf.good()){
        cout << "Invalid File Name(s)";
        return 0;
    }
    while (!inf.eof()){
        string firstName, lastName, socNum, deptNum;
        double wage;
        inf >> lastName >> firstName >> socNum >> deptNum >> wage;
        Employee employee1(firstName, lastName, socNum, deptNum, wage), employee2(firstName, lastName, socNum, deptNum, wage);
        S1.Push(employee1);
        Q1.Enqueue(employee2);
    }
    inf.close();
    inf.clear();
    inf.open(name2);
    if (!inf.good()){
        cout << "Invalid File Name(s)";
        return 0;
    }
    while (!inf.eof()){
        string firstName, lastName, socNum, deptNum;
        double wage;
        inf >> lastName >> firstName >> socNum >> deptNum >> wage;
        Employee employee1(firstName, lastName, socNum, deptNum, wage), employee2(firstName, lastName, socNum, deptNum, wage);
        S2.Push(employee1);
        Q2.Enqueue(employee2);
    }
    inf.close();

    // Print First Time
    cout << "\nSTACK #1\n_______\n";
    S1.printStack();
    cout << "\nQUEUE #1\n_______\n";
    Q1.printQueue();
    cout << "\nSTACK #2\n_______\n";
    S2.printStack();
    cout << "\nQUEUE #2\n_______\n";
    Q2.printQueue();

    // Sorting
    sort(S1.getElts().begin(), S1.getElts().end(), less<Employee>());
    sort(S2.getElts().begin(), S2.getElts().end(), less<Employee>());
    sort(Q1.getElts().begin(), Q1.getElts().end(), less<Employee>());
    sort(Q2.getElts().begin(), Q2.getElts().end(), less<Employee>());

    // Printing Post Sort
    cout << "AFTER SORTING ALL VECTORS\n";
    cout << "\nSTACK #1\n_______\n";
    S1.printStack();
    cout << "\nQUEUE #1\n_______\n";
    Q1.printQueue();
    cout << "\nSTACK #2\n_______\n";
    S2.printStack();
    cout << "\nQUEUE #2\n_______\n";
    Q2.printQueue();

    // Using Overloaded +
    myQueue Q3 = Q1 + Q2;
    myStack S3 = S1 + S2;
    cout << "After overloaded operator +\n";
    cout << "\nSTACK #3\n_______\n";
    S3.printStack();
    cout << "\nQUEUE #3\n_______\n";
    Q3.printQueue();

    // Sort Q3/S3
    sort(S3.getElts().begin(), S3.getElts().end(), less<Employee>());
    sort(Q3.getElts().begin(), Q3.getElts().end(), less<Employee>());

    // Print Sorted Q3/S3
    cout << "After SORTING\n";
    cout << "\nSTACK #3\n_______\n";
    S3.printStack();
    cout << "\nQUEUE #3\n_______\n";
    Q3.printQueue();

    // Popping from S2 and Q2
    cout << "REMOVING ALL ITEMS FROM S2 and Q2\n\n";
    cout << "Items POPPED from Stack S2 \n\n";
    while (!S2.isempty()){
        Employee employee = S2.Pop();
        cout << "POPPING " << employee << "\n\n";
    }

    try {
        S2.Pop();
    } catch (exception e){
        cout << "ERROR - STACK is EMPTY\n\n";
    }

    cout << "Items DEQUEUED from Queue Q2 \n\n";
    while (!Q2.isempty()){
        Employee employee = Q2.Dequeue();
        cout << "DEQUEUEING  " << employee << "\n\n";
    }

    try {
        Q2.Dequeue();
    } catch (exception e){
        cout << "ERROR - QUEUE is EMPTY\n\n";
    }

    cout << "PROGRAM EXECUTION IS COMPLETE";
    return 0;
}