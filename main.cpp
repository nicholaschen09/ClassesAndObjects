/* ------------------------
 Nicholas Chen
 ICS4U1 - 2
 Assignment #4: Creating Classes and Objects
--------------------------- */
#include "assign_4.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {

  double depositAmount = 2000.0;
  double withdrawAmount = 400.0;
  string withdraw;
  const int numAccounts = 5;
  Account accounts[numAccounts];

  ifstream file("data.txt");

  if (file.is_open()) {
    for (int i = 0; i < numAccounts; i++) {
      string name;
      int id;
      double balance;

      // gets the information from the file
      getline(file, name);
      file >> id >> balance;

      file.ignore();

      // assigning each user their info
      accounts[i].setName(name);
      accounts[i].setId(id);
      accounts[i].setBalance(balance);
    }

    file.close();

    // prints each users info
    for (int i = 0; i < numAccounts; i++) {
      cout << "Name: " << accounts[i].getName() << endl;
      cout << "ID: " << accounts[i].getId() << endl;
      cout << fixed << setprecision(2) << "Balance: $"
           << accounts[i].getBalance() << endl;

      // deposits money for each person
      accounts[i].deposit(depositAmount);
      cout << "Deposit successful. " << endl;
      cout << endl;
      cout << "Name: " << accounts[i].getName() << endl;
      cout << "ID: " << accounts[i].getId() << endl;
      cout << "New balance: $" << fixed << setprecision(2)
           << accounts[i].getBalance() << endl;

      // checks if enough money to withdraw
      if (withdrawAmount > accounts[i].getBalance()) {
        cout << "Insufficient funds" << endl;
      } else {
        accounts[i].withdraw(withdrawAmount);
        cout << "Withdrawal successful. " << endl;
        cout << endl;

        // prints out person info after deposit and withdrawal
        cout << "name: " << accounts[i].getName() << endl;
        cout << "ID: " << accounts[i].getId() << endl;
        cout << "New balance: $" << fixed << setprecision(2)
             << accounts[i].getBalance() << endl;
      }
      // splits each users info
      if (i < numAccounts - 1) {
        cout << endl;
      }
    }
  } else {
    cout << "unable to open data.txt file" << endl;
  }

  cout << endl;

  double a;
  double b;
  double c;

  cout << "Enter three values for a b and c: " << endl;
  cin >> a >> b >> c;

  QuadraticEquation equation(a, b, c);

  // function for computing the discriminant
  double discriminant = equation.getDiscriminant();

  // checking if discriminant shows two roots
  if (discriminant > 0) {
    double root1 = equation.getRoot1();
    double root2 = equation.getRoot2();
    cout << "Two real roots are " << root1 << " and " << root2 << endl;

    // checks for if only one real root
  } else if (discriminant == 0) {
    double root1 = equation.getRoot1();
    cout << "One real root " << root1 << endl;

    // condition for no real roots
  } else {
    cout << "The equation has no real roots" << endl;
  }

  return 0;
}
