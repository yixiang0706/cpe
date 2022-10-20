#include<iostream>
#include<map>
#include<string>

using namespace std;
int main() {
	map<string, string> Map;
	string ans;
	while (getline(cin,ans) && ans!= "") {
		string Eng = ans;
		string Unknown = ans;
		size_t i;
		for (i = 0; i < ans.length(); i++) {
			if (ans[i] == ' ')
				break;
		}
		Eng.resize(i);
		i++;
		size_t j = 0;
		for (; i < ans.length(); j++,i++) {
			Unknown[j] = ans[i];
		}
		Unknown.resize(j);
		Map[Unknown] = Eng;
	}

	string que;
	while (getline(cin, que) && que != "") {
		if (Map.find(que) == Map.end())
			cout << "eh" << endl;
		else
			cout << Map.find(que)->second << endl;
	}
	return 0;
}