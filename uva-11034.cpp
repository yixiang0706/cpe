#include<iostream>
#include<queue>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int length, car;
		cin >> length >> car;
		length *= 100;
		queue<int>left, right;
		string side;
		int temp;
		for (int i = 0; i < car; i++) {
			cin >> temp >> side;
			if (side == "left")
				left.push(temp);
			else
				right.push(temp);
		}
		int times = 0;
		string curSide = "left";
		while (!left.empty() || !right.empty()) {
			int sum = 0;
			if (curSide == "left") {
				while (!left.empty()) {
					if (sum + left.front() >= length)
						break;
					sum += left.front();
					left.pop();
				}
				curSide = "right";
			}
			else {
				while (!right.empty()) {
					if (sum + right.front() >= length)
						break;
					sum += right.front();
					right.pop();
					
				}
				curSide = "left";
			}
			times++;
		}
		cout << times << endl;
	}
}