#include<iostream>
using namespace std;
int main()
{
	int number,answer;
	while (cin >> number) {
		if (number == 0)
			break;
		while (1) {
			answer = 0;
			answer += number / 1000000000;
			number %= 1000000000;
			answer += number / 100000000;
			number %= 100000000;
			answer += number / 10000000;
			number %= 10000000;
			answer += number / 1000000;
			number %= 1000000;
			answer += number / 100000;
			number %= 100000;
			answer += number / 10000;
			number %= 10000;
			answer += number / 1000;
			number %= 1000;
			answer += number / 100;
			number %= 100;
			answer += number / 10;
			number %= 10;
			answer += number;
			if (answer < 10)
				break;
			else
				number = answer;
		}
		cout << answer << endl;
	}
	return 0;
} 
