#include "pch.h"
#include <iostream>


using namespace std;

class Bank {
public:

	Bank() {};
	Bank(int b, const char * n)
	{
		balance = b;
		number = n;
	}

	void setBalance(int b)
	{
		balance = b;
	}

	int getBalance()
	{
		return balance;
	}

	void deposit(int amount)
	{
		balance += amount;
	}


	void withDraw(int amount)
	{

		if (balance >= amount)
			balance -= amount;

		else
			cout << "잔액이 부족합니다. " << endl;
		

	}

private:
	int balance = 0;
	const char * number;
};

int main()
{
	Bank user1(100000, "1111");
	cout << "현재잔액 : " << user1.getBalance() << endl;
	user1.deposit(100000);
	cout << "after deposit(100000) 현재잔액: " << user1.getBalance() << endl;
	user1.withDraw(100000);
	cout << "after withdraw(100000) 현재잔액: " << user1.getBalance() << endl;

}

