// Carter Nickelson Homework 5

#pragma once
#include<string>

using namespace std;

// class with basic get and set functions in addition to constructors
class Transaction
{
	char type;
	double amount;
	double balance;
	string description;
public:
	Transaction(char type, double amount, double balance, string description)
	{
		this->type = type;
		this->amount = amount;
		this->balance = balance;
		this->description = description;
	}
	Transaction()
	{
		type = 'w';
		amount = 0;
		balance = 0;
		description = "";
	}

	char getType()
	{
		return type;
	}

	double getAmount()
	{
		return amount;
	}

	double getBalance()
	{
		return balance;
	}
};