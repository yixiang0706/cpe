#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int B, sg, sb;
		cin >> B >> sg >> sb;
		int temp;
		multiset<int> green;
		multiset<int> blue;
		for (int j = 0; j < sg; j++) {
			cin >> temp;
			green.insert(temp);
		}
		for (int j = 0; j < sb; j++) {
			cin >> temp;
			blue.insert(temp);
		}

		while (!blue.empty() && !green.empty()) {
			vector<int> temp;
			for (int j = 0; j < B; j++) {
				if (green.empty() || blue.empty())
					break;
				set<int>::reverse_iterator it1 = green.rbegin();
				set<int>::reverse_iterator it2 = blue.rbegin();
				
				temp.push_back(*it1 - *it2);
				set<int>::iterator it3 = green.end();
				it3--;
				green.erase(it3);
				set<int>::iterator it4 = blue.end();
				it4--;
				blue.erase(it4);
			}

			for (vector<int>::iterator ptr = temp.begin();ptr!=temp.end();ptr++) {
				if (*ptr > 0){
					green.insert(*ptr);
				}else if (*ptr < 0){
					blue.insert(-*ptr);
				}
			}
			temp.clear();
		}

		if (blue.empty() && green.empty())
			cout << "green and blue died" << endl;
		else if (blue.empty() && !green.empty()){
			cout << "green wins" << endl;
			for (set<int>::reverse_iterator it = green.rbegin(); it != green.rend(); it++) {
				cout << *it << endl;
			}
		}else{
			cout << "blue wins" << endl;
			for (set<int>::reverse_iterator it = blue.rbegin(); it != blue.rend(); it++) {
				cout << *it << endl;
			}
		}

		if(i!=cases-1)
			cout << endl;
	}
	return 0;
}