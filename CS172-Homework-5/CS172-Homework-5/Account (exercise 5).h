#pragma once
#include<string>
#include"Transaction.h"
#include"Vector(exercise 3).h"

using namespace std;

class Account
{
	int id;
	double balance;
	double annualInterestRate;
	string name;
public:
	vector<Transaction> transactions;
	Account();
	Account(string, int, double);
	int getId();
	void setId(int);
	double getBalance();
	void setBalance(double);
	double getInterest();
	void setInterest(double);
	double getMonthlyInterest();
	void withdraw(double amount);
	void deposit(double amount);
	void displayTransactions(Transaction&);
};