#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
int main() {
	string in;
	vector<stack<char>> a;
	int count = 1;
	while (cin >> in, in != "end") {
		a.clear();
		stack<char> v;
		v.push(in[0]);
		a.emplace_back(v);
		
		for (int j = 1; j < in.length(); j++) {
			for (int i = 0; i < a.size(); i++) {
				if (a[i].top() >= in[j]) {
					a[i].push(in[j]);
					break;
				}
				else if(i == a.size() - 1) {
					stack<char> tmp;
					tmp.push(in[j]);
					a.emplace_back(tmp);
					break;
				}
			}
		} 
		cout << "Case " << count++ << ": " << a.size() << endl;
	}
}