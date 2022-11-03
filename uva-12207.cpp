#include<iostream>
#include<deque>
using namespace std;
int main() {
	int cases, population;
	int count = 0;
	while (cin >> population >> cases) {
		if (population == 0 && cases == 0){
			break;
		}
		count++;
		
		int minimum;
		if (population < cases)
			minimum = population;
		else
			minimum = cases;

		deque<int> list;

		for (int j = 1; j <= minimum;j++) {
			list.push_back(j);
		}

		int no = 0;
		while (cases--) {
			char statement;
			cin >> statement;
			int find;
			if (statement == 'E') {
				cin >> find;
				deque<int>::iterator it;
				list.insert(list.begin() + no, find);
				for (it = list.begin() + no + 1; it != list.end(); it++) {
					if (*it == find) {
						break;
					}
				}
				if(it != list.end())
					list.erase(it);
			}
			else {
				list.push_back(*(list.begin() + no));
				no++;
			}
		}
		cout << "Case " << count << ":" << endl;
		for (deque<int>::iterator it = list.begin(); no > 0; it++, no--) {
			cout << *it << endl;
		}
	}
	return 0;
}