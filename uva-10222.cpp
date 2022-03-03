#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line;
	while (getline(cin, line)) {
		for (int j = 0; j < line.length(); j++) {
			if (line[j] >= 65 && line[j] <= 90) {
				line[j] += 32;
			}
		}
		for (int i = 0; i < line.length(); i++) {
			switch (line[i]) {
			case 'd':
				cout << "a";
				break;
			case 'm':
				cout << "b";
				break;
			case 'b':
				cout << "c";
				break;
			case 'g':
				cout << "d";
				break;
			case 't':
				cout << "e";
				break;
			case 'h':
				cout << "f";
				break;
			case 'j':
				cout << "g";
				break;
			case 'k':
				cout << "h";
				break;
			case 'p':
				cout << "i";
				break;
			case 'l':
				cout << "j";
				break;
			case ';':
				cout << "k";
				break;
			case '\'':
				cout << "l";
				break;
			case '.':
				cout << "m";
				break;
			case ',':
				cout << "n";
				break;
			case '[':
				cout << "o";
				break;
			case ']':
				cout << "p";
				break;
			case 'e':
				cout << "q";
				break;
			case 'y':
				cout << "r";
				break;
			case 'f':
				cout << "s";
				break;
			case 'u':
				cout << "t";
				break;
			case 'o':
				cout << "u";
				break;
			case 'n':
				cout << "v";
				break;
			case 'r':
				cout << "w";
				break;
			case 'v':
				cout << "x";
				break;
			case 'i':
				cout << "y";
				break;
			case 'c':
				cout << "z";
				break;
			case '\ ':
				cout << ' ';
				break;
			}
		}
		cout << endl;
	}
	
	return 0;
}