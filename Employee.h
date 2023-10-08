#include <string>
#pragma once
using namespace std;
class Employee {
private:
    string firstName;
    string lastName;
    string socsecnum;
    string deptNum;
    double wage;
public:
    Employee();
    Employee(string firstName, string lastName, string socsecnum, string deptNum, double wage);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setSocSecNum(string socsecnum);
    void setDeptNum(string deptNum);
    void setWage(double wage);
    string getFirstName();
    string getLastName();
    string getSocSecNum();
    string getDeptNum();
    double getWage();
    bool operator<(const Employee & other) const;
    friend ostream& operator<<(ostream& stream, Employee& employee);
};