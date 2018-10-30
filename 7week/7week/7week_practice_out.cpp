// 7week.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{


	ofstream outClientFile("client.txt", ios::out);

	if (!outClientFile)
	{
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Enter the account, name, and balance" << endl << "Enter end-of-file to end input \n?";
	int account;
	string name;
	double balance;

	while (cin >> account >> name >> balance)
	{
		outClientFile << account << ' ' << name << ' ' << balance << endl;
		cout << "? ";
	}
	





}
