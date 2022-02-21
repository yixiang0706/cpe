#include<iostream>
using namespace std;
int main()
{
	int i, j,times,c;
	while (1) {
		times = 0;
		c = 0;
		cin >> i >> j;
		if (i == 0 && j == 0) {
			break;
		}
		for (int k = 10; k <= 1000000000; k *= 10) {
			int n = (i % k - i % (k / 10)) / (k / 10) + ((j % k - j % (k / 10)) / (k / 10));
			if ( n+c > 9) {
				times++;
				c =  1 ;
			}
			else {
				c = 0;
			}
		}
		if (times == 0) {
			cout << "No carry operation."<<endl;
		}
		else if (times == 1) {
			cout << "1 carry operation." << endl;
		}
		else
			cout<<times <<" carry operations." << endl;
	}
	return 0;
}