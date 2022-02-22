#include<iostream>
using namespace std;
int main()
{
	string number;
	int i,j;
	while (cin >> number) {
		if (number == "0") {
			break;
		}
		int evensum = 0, oddsum = 0;
		for (j = 0; number[j] != '\0'; j++) {
			if (j % 2 == 0) {
				oddsum += number[j] - '0';
			}
			else {
				evensum += number[j] - '0';
			}
		}
		int ans = evensum - oddsum;
		if (ans % 11 == 0) {
			cout <<number<< " is a multiple of 11." << endl;
		}
		else {
			cout <<number<< " is not a multiple of 11." << endl;
		}
	}
	return 0;
}