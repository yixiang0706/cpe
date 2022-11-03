#include<iostream>
#include<queue>
using namespace std;
int main() {
	int cases,num;
	while (cin >> cases, cases != 0) {
		priority_queue<int, vector<int>, greater<int>> list;
		for (int i = 0; i < cases; i++) {
			cin >> num;
			list.push(num);
		}
		int temp, result = 0;
		while (list.size() >= 2) {
			temp = list.top();
			list.pop();
			temp += list.top();
			list.pop();
			list.push(temp);
			result += temp;
		}
		cout << result << endl;
	}
	return 0;
}