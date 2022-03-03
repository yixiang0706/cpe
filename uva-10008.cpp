#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char sentence;
	string line;
	int ascii;

	int english[26] = {0};
	for (int i = 0; i < n; i++) {
		getline(cin, line);
		if (line=="\0") {
			n++;
		}
		else {
			int length = line.length();
			for (int j = 0; j < length; j++) {
				if (line[j] <= 90 && line[j] >= 65) {
					ascii=line[j] - 65 ;
					//cout << ascii;
					english[ascii]++;
				}
				else if (line[j] <= 122 && line[j] >= 97) {
					ascii = line[j] - 97 ;
					//cout << ascii;
					english[ascii]++;
				}
			}
		}
	}

	int max,maxi;
	int maxenglish;
	char newtemp[26];
	int i,j=0;

	while (1) {
		max = 0;

		for (i = 0; i < 26; i++) {//get max
			if (english[i] > max) {
				max = english[i];
				maxi = i;
			}
		}
		if (max == 0) {
			break;
		}

		newtemp[j] = 'A'+maxi;
		cout << newtemp[j] << " " << max << endl;
		j++;
		english[maxi] = 0;
	}

	return 0;
}