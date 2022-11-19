#include<iostream>
#include<stack>
using namespace std;
string in, target;
void dfs(stack<char>start, string final,stack<char>stack,string output) {
	if (4*final.size()-1 == output.size()) {
		if (final == target) {
			cout << output << endl;
			return;
		}
	}
	if (start.size() > 0) {
		auto tmp1 = stack;
		auto tmp2 = start;
		tmp1.push(tmp2.top());
		tmp2.pop();
		if (output.length() == 0)
			dfs(tmp2, final, tmp1, output + "i");
		else
			dfs(tmp2, final, tmp1, output + " i");
	}
	if (stack.size() > 0 && stack.top() == target[final.length()]) {
		auto tmp1 = stack;
		tmp1.pop();
		dfs(start, final + stack.top(), tmp1, output + " o");
	}
}

int main() {
	while (cin >> in >> target) {
		stack<char>start, stack;
		for (int i = in.size() - 1; i >= 0; i--)
			start.push(in[i]);

		cout << "[" << endl;
		if (in.size() == target.size())
			dfs(start,"",stack,"");
		cout << "]" << endl;
	}
}