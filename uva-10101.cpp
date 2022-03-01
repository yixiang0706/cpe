#include <iostream>
#include <iomanip>//setw
using namespace std;

void recursive(long long int number);

int main()
{
	long long int number;
	int i = 1;
	while (cin >> number) {
		cout << setw(4) << i << ".";
		recursive(number);
		if (number == 0) {
			cout <<" 0";
		}
		cout << endl;
		i++;
	}
}

void recursive(long long int number)
{
	if (number / 10000000 > 0) {
		recursive(number / 10000000);
		cout << " kuti";
		number %= 10000000;
		recursive(number);
	}
	else if (number / 100000 > 0) {
		cout << " " << number / 100000 << " lakh";
		number %= 100000;
		recursive(number);
	}
	else if (number / 1000 > 0) {
		cout << " " << number / 1000 << " hajar";
		number %= 1000;
		recursive(number);
	}
	else if (number / 100 > 0) {
		cout <<" " << number / 100 << " shata";
		number %= 100;
		recursive(number);
	}
	else {
		if (number > 0) {
			cout << " " << number;
		}
	}
}