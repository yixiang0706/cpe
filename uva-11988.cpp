#include<iostream>
#include<list>
#include<string>
using namespace std;
int main() {
	string sentence;
	while (getline(cin, sentence)) {
		list<char> List;
		list<char>::iterator it = List.begin();
		for (int i = 0; i < sentence.length(); i++)
		{
			if (sentence[i] == '[') {
				it = List.begin();
			}
			else if (sentence[i] == ']') {
				it = List.end();
			}
			else {
				List.insert(it,sentence[i]);
			}
		}
		for (it = List.begin();it != List.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}