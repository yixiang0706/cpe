#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		int number[3000] = {0};
		int	difference[3000] = {0};

		for (int i = 0;i < n; i++) {
			cin >> number[i];
			if (i >= 1) {
				difference[i - 1] = number[i] - number[i - 1];
				if (difference[i - 1] < 0) {
					difference[i - 1] = -difference[i - 1];
				}
			}
		}

		sort(difference,difference+n-1);
		
		bool status=true;
		for (int i = 0; i < n - 1; i++) {
			if (difference[i] != i+1) {
				status = false;
				break;
			}
		}

		if (status) {
			cout << "Jolly" << endl;
		}
		else {
			cout << "Not jolly" << endl;
		}
	}
	return 0;
}