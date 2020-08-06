#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

int main(int argc, char *argv[])
{ 
	if(argc != 2 || !isdigit(argv[1][0]) || strlen(argv[1]) < 2)
	{
        	cout << "Incorrect usage: luhn [num>=10]" << endl;
    		return 1;
	}

	string input = argv[1];
	int odds = 0, evens = 0, buffer = 0;
	
	if(input.size() % 2 != 0)
			buffer = 1;
	
	for(int i = input.size()-1; i >= 0; i--)
	{
		if((i+buffer) % 2 == 0)
		{
			if(((int) input[i] - '0') * 2 < 10)
			{
				evens += ((int) input[i] - '0') * 2;
			}
			else
			{
				int temp = ((int) input[i] - '0') * 2;
				evens += ((temp/10) % 10) + (temp % 10);
			}
		}
		else
		{
			odds += (int) input[i] - '0';
		}
	}

	if((evens + odds) % 10 == 0)
		cout << "Luhn test passed." << endl;
	else
		cout << "Luhn test failed." << endl;
	
    return 0;
}
