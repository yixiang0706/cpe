#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct datas {
	int id;
	int period;
	int time;
	bool operator>(datas right)const {
		if (time > right.time) {
			return true;
		}
		else if (time == right.time) {
			if (id > right.id)
				return true;
			else
				return false;
		}
		return false;
	}
};
int main() {
	priority_queue<datas,vector<datas>,greater<datas>> list;
	string s;
	while (cin >> s) {
		if (s == "#")
			break;
		int numberID, Period;
		cin >> numberID >> Period;
		datas data;
		data.id = numberID;
		data.period = Period;
		data.time = Period;
		list.push(data);
	}
	int cases;
	cin >> cases;
	while (cases--) {
		datas temp = list.top();
		cout << temp.id << endl;
		temp.time += temp.period;
		list.pop();
		list.push(temp);
	}
	return 0;
}