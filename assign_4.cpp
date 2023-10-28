#include "assign_4.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Class Account//

// Constructor with default values
Account::Account() : id(0), balance(0.0) {}
Account::Account(const string &name, int id, double balance) {
  this->customerName = name;
  this->id = id;
  this->balance = balance;
}
string Account::getName() const { return customerName; }

void Account::setName(const string &name) { customerName = name; }

// if not enough money to withdraw, let user know
void Account::withdraw(double amount) {
  if (amount <= balance) {
    balance -= amount;
  } else {
    cout << "Insufficient funds." << endl;
  }
}

void Account::deposit(double amount) { balance += amount; }

int Account::getId() const { return id; }

void Account::setId(int newId) { id = newId; }

double Account::getBalance() const { return balance; }

void Account::setBalance(double newBalance) { balance = newBalance; }

// Class Quadratic Equation//

// Initializes the coefficients of the quadratic equation
QuadraticEquation::QuadraticEquation(double a, double b, double c) {
  this->a = a;
  this->b = b;
  this->c = c;
}
double QuadraticEquation::getA() const { return a; }

double QuadraticEquation::getB() const { return b; }

double QuadraticEquation::getC() const { return c; }

// function for computing discriminant
double QuadraticEquation::getDiscriminant() const {
  return (b * b) - (4 * a * c);
}

double QuadraticEquation::getRoot1() const {
  double discriminant = getDiscriminant();

  // If discriminant is negative, no real roots exist
  if (discriminant < 0) {
    return 0;
  } else {
    return (-b + sqrt(discriminant)) / (2 * a);
  }
}
double QuadraticEquation::getRoot2() const {
  double discriminant = getDiscriminant();

  // If discriminant is negative, no real roots exist
  if (discriminant < 0) {
    return 0;
  } else {
    return (-b - sqrt(discriminant)) / (2 * a);
  }
}
