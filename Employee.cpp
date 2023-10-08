#include "Employee.h"
#include <string>
#include <ostream>
using namespace std;
Employee::Employee() {

}

Employee::Employee(string firstName, string lastName, string socsecnum, string deptNum, double wage) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->socsecnum = socsecnum;
    this->deptNum = deptNum;
    this->wage = wage;
}

void Employee::setDeptNum(std::string deptNum) {
    this->deptNum = deptNum;
}

void Employee::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Employee::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Employee::setSocSecNum(std::string socsecnum) {
    this->socsecnum = socsecnum;
}

void Employee::setWage(double wage) {
    this->wage = wage;
}

string Employee::getDeptNum() {
    return deptNum;
}

string Employee::getFirstName() {
    return firstName;
}

string Employee::getLastName() {
    return lastName;
}

string Employee::getSocSecNum() {
    return socsecnum;
}

double Employee::getWage() {
    return wage;
}

bool Employee::operator<(const Employee &other) const {
    // Test deptNum, then last, then first names
    if (deptNum < other.deptNum){
        return true;

    // Test Last Name
    } else if (deptNum == other.deptNum){
        if (lastName < other.lastName){
            return true;

    // Test First Name
        } else if (lastName == other.lastName){
            if (firstName < other.firstName){
                return true;
            }
        }
    }

    // Return false if fails to return on any prior test
    return false;
}

