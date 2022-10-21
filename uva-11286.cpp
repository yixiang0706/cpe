#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;
int main() {
	int cases;
	while (cin >> cases && cases != 0) {
		map<string, int> Map;
		for (size_t i = 0; i < cases; i++) {
			string temp[5];
			string line;
			for (size_t j = 0; j < 5; j++) {
				cin >> temp[j];
			}
			sort(temp,temp+5);
			for (size_t j = 0; j < 5; j++) {
				line += temp[j];
			}
			Map[line]++;
		}

		int max = 0;

		for (map<string, int>::iterator it = Map.begin(); it != Map.end(); it++) {
			if (it->second > max)
				max = it->second;
		}

		int final = 0;
		for (map<string, int>::iterator it = Map.begin(); it != Map.end(); it++) {
			if (it->second == max)
				final += it->second;
		}
		cout << final << endl;
	}
	return 0;
}