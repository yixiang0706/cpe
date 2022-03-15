#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2, replace;
	while (getline(cin, str1) && getline(cin, str2)) {
		int timeA[26] = {0};
		int timeB[26] = {0};
		for (int i = 0; i < str1.length(); i++) {
			timeA[str1[i] - 'a']++;
		}
		for (int i = 0; i < str2.length(); i++) {
			timeB[str2[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (timeA[i] > 0 && timeB[i] > 0) {
				int time;
				if (timeA[i] > timeB[i]) {
					time = timeB[i];
				}
				else {
					time = timeA[i];
				}
				char word = 'a' + i;
				for (int j = 0; j < time; j++) {
					cout << word;
				}
			}
		}
		cout << endl;
		str1 = str2 = "\0";
		//cout << str1 << " " << str2;
	}
	return 0;
}