#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		unordered_set<int> snowflake;
		vector<int> identity;
		int line;
		int size = 0;
		int temp;
		cin >> line;
		while (line--) {
			cin >> temp;
			if (snowflake.count(temp)) {
				if(snowflake.size() > size)
					size = snowflake.size();
			}
			while (snowflake.count(temp)) {
				snowflake.erase(*identity.begin());
				identity.erase(identity.begin());
			}
			snowflake.insert(temp);
			identity.push_back(temp);
		}
		if (snowflake.count(temp)) {
			if (snowflake.size() > size)
				size = snowflake.size();
		}
		cout <<size << endl;
	}

	return 0;
}