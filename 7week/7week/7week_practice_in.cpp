// 7week.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;


enum RequestType { ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END };

int getRequest()
{
	int request;

	cout << "\nEnter request" << endl
		<< "1 - List accounts with zero balances" << endl
		<< "2 - List accounts with credit balances" << endl
		<< "3 - List accounts with debit balances" << endl
		<< "4 - End of run" << fixed << showpoint;

	do
	{
		cout << "\n?";
		cin >> request;
	} while (request < ZERO_BALANCE || request > END);

		return request;
}


bool shouldDisplay(int type, double balance)
{
	if (type == ZERO_BALANCE && balance == 0)
		return true;

	if (type == CREDIT_BALANCE && balance < 0)
		return true;

	if (type == DEBIT_BALANCE && balance > 0)
		return true;

	return false;

}

void outputline(int account, const string & name, double balance)
{
	cout << left << setw(10) << account << setw(13) << name
		<< setw(7) << setprecision(2) << right << balance << endl;
}


int main()
{

	ifstream inClientFile;
	inClientFile.open("client.txt", ios::in);

	if (!inClientFile)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}


	int account;
	string name;
	double balance;

	int request = getRequest();

	while (request != END)
	{
		switch (request)
		{
		case ZERO_BALANCE:
			cout << "\nAccounts with zero balances:\n";
			break;

		case CREDIT_BALANCE:
			cout << "\nAccounts with credit balances:\n";
			break;
			
		case DEBIT_BALANCE:
			cout << "\nAccounts with debit balances:\n";
			break;
		}
		

		inClientFile >> account >> name >> balance;


		while (!inClientFile.eof())
		{
			
			if (shouldDisplay(request, balance))
				outputline(account, name, balance);

			inClientFile >> account >> name >> balance;


		}

		inClientFile.clear();
		inClientFile.seekg(0);
		
		request = getRequest();


		cout << "End of run." << endl;

	}


}
