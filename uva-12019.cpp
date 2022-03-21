#include<iostream>
using namespace std;
int main()
{
	int cases,M,D;
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		int date = 6;
		cin >> M >> D;
		while (M-1 > 0) {
			date += month[M-1];
			M--;
		}
		date += D-1;
		date %= 7;
		switch (date)
		{
		case 1:
			cout << "Monday" << endl;
			break;
		case 2:
			cout << "Tuesday" << endl; 
			break;
		case 3:
			cout << "Wednesday" << endl;
			break;
		case 4:
			cout << "Thursday" << endl;
			break;
		case 5:
			cout << "Friday" << endl;
			break;
		case 6:
			cout << "Saturday" << endl;
			break;
		case 0:
			cout << "Sunday" << endl;
			break;
		default:
			break;
		}
	}
}