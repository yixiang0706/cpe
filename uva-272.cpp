#include<iostream>
#include<string>
using namespace std;
int main()
{
	string sentence;
	int index=0;
	while (getline(cin, sentence)) {
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] != '\"') {
				cout << sentence[i];
			}
			else if (index == 0) {
				cout << "``";
				index = 1;
			}
			else {
				cout << "''";
				index = 0;
			}
		}
		cout << endl;
	}
	return 0;
}