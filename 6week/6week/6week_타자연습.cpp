
#include "pch.h"
#include <iostream>
#include <string>



using namespace std;


void typing(string origin, string input)
{

	int i = 0;
	while (origin[i] != '\0')
	{
		if (origin[i] != input[i])
		{
			cout << "Wrong Answer !" << endl;
			return;
		}

		i++;

	}

	cout << "Correct Answer !" << endl;
	return;


}

int main()
{

	
	string origin = "Hello World!";

	char input[100];


	cout << "type sentence above:";

	cin.getline(input, 100);

	typing(origin, input);

	

}
