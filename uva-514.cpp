#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main() {
	int cases;int in;
	while (cin >> cases, cases != 0) {
		while (cin >> in, in != 0) {
			queue<int>a;
			a.push(in);
			for (int i = 1; i < cases; i++)
			{
				cin >> in;
				a.push(in);
			}
			stack<int>tmp;
			for (int i = 1; i <= cases; i++) {
				tmp.push(i);
				while (!tmp.empty() && a.front() == tmp.top())
				{
					a.pop(); tmp.pop();
				}
			}

			if (a.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
}