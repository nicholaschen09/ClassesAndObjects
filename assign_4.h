#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Class Account//

class Account {
private:
  string customerName;
  int id;
  double balance;

public:
  Account();
  Account(const string &name, int id, double balance);

  string getName() const;

  int getId() const;

  void setName(const string &name);

  void setId(int newId);

  double getBalance() const;

  void setBalance(double newBalance);

  void deposit(double amount);

  void withdraw(double amount);
};

// class QuadraticEquation {

class QuadraticEquation {
private:
  double a;
  double b;
  double c;

public:
  QuadraticEquation(double a, double b, double c);

  double getA() const;

  double getB() const;

  double getC() const;

  double getDiscriminant() const;

  double getRoot1() const;

  double getRoot2() const;
};