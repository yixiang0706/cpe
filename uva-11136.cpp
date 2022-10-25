#include<iostream>
#include<set>
using namespace std;
int main() {
	int cases;
	long long int sum = 0;
	while (cin >> cases) {
		multiset<int> theset;
		sum = 0;
		if (cases == 0)
			break;
		for (int i = 0; i < cases; i++) {
			int j;
			cin >> j;
			int temp;
			while (j--) {
				cin >> temp;
				theset.insert(temp);
			}
			set<int>::iterator min = theset.begin();
			set<int>::iterator max = --theset.end();
			sum += (*max - *min);
			theset.erase(min);
			theset.erase(max);
		}
		cout << sum << endl;
	}
	return 0;
}