#include<iostream>
using namespace std;
int main()
{
	int count;
	int point[500] = {};
	cin >> count;
	
	for (int i = 0; i < count; i++) {
		int person;
		cin >> person;
		for (int j = 0; j < person; j++) {
			cin >> point[j];
		}
		for (int k = 0; k <person-1 ; k++) {
			int replace;
			for (int l = 0; l < person-1; l++) {
				if (point[l] > point[l + 1]) {
					replace = point[l];
					point[l] = point[l + 1];
					point[l + 1] = replace;
				}
			}
		}
		int middle = point[person / 2];
		int ans=0, replace;
		for (int l = 0; l < person; l++) {
			replace = point[l] - middle;
			if (replace < 0) {
				ans -= replace;
			}
			else
				ans += replace;
		}
		cout << ans<<endl;
	}
	return 0;
}