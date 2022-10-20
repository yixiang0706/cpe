#include<iostream>
#include<map>
#include<string>
#include<iomanip>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	cin.ignore();
	cin.ignore();
	for (int i = 0; i < cases; i++) {
		map<string, double>Map;
		string s;
		while (getline(cin,s) ) {
			if (s != "") {
				Map[s]++;
			}
			else
				break;
		}
		double total = 0;
		for (map<string, double>::iterator it = Map.begin(); it != Map.end(); it++) {
			total += it->second;
		}

		for (map<string, double>::iterator it = Map.begin(); it != Map.end(); it++) {
			double percent = it->second / total * 100;
			if (it != Map.end()--)
				cout << it->first << " " << fixed << setprecision(4) << percent << endl;
			else
				cout << it->first << " " << fixed << setprecision(4) << percent;
		}

		if(i != cases-1)
			cout << endl;
	}
	return 0;
}