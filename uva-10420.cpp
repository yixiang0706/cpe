#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int amount,count=1;
	string name;
	string country[2000];
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		cin >> country[i];
		getline(cin,name);//string±M¥Î
	}

	sort(country, country + amount);
	int j;
	for (int i = 0; i < amount;) {
		cout << country[i]<<" ";
		for (j = i + 1; j < amount;j++) {
			if (country[i] != country[j]) {
				break;
			}
			else {
				count++;
			}
		}
		i = j;
		cout << count << endl;
		count = 1;
	}
	return 0;
}