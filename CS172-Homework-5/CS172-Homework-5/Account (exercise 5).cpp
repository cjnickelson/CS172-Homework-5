#include"Account (exercise 5).h"
#include"Vector(exercise 3).h"
#include"Transaction.h"

// constructors, with or without arguments and get and set functions are standard
Account::Account()
{
	id = 0;
	balance = 0;
	annualInterestRate = 0;
	name = "";
}

Account::Account(string n, int i, double b)
{
	name = n;
	id = i;
	balance = b;
}

int Account::getId()
{
	return id;
}

void Account::setId(int value)
{
	id = value;
}

double Account::getBalance()
{
	return balance;
}

void Account::setBalance(double b)
{
	balance = b;
}

double Account::getInterest()
{
	return annualInterestRate;
}

void Account::setInterest(double value)
{
	annualInterestRate = value;
}

// monthly interest is just the annual interest divided by 12
double Account::getMonthlyInterest()
{
	return annualInterestRate / 12;
}

// this withdraw allows the user to take a certain amount of money out of the account, changes the balance of the account, and records the transaction in the transaction vector
void Account::withdraw(double amount)
{
	string description = "Taking out a certain amount of money from the account";
	balance -= amount;
	Transaction t('w', amount, balance, description);
	transactions.push_back(t);
}

// the depoist function does the same as the withdraw function, except it takes money out
void Account::deposit(double amount)
{
	string description = "Putting a certain amount of money into the acccount";
	balance += amount;
	Transaction t('d', amount, balance, description);
	transactions.push_back(t);
}

// This function will display the traits of a transaction, namely the type, amount, and new balance
void displayTransactions(Transaction& t)
{
		cout << t.getType() << t.getAmount() << t.getBalance() << endl;;
}