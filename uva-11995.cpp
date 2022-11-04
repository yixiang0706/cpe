#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int main() {
	int cases;
	while (cin >> cases) {
		stack<int> Stack;
		queue<int> Queue;
		priority_queue<int> Priority;
		int statusS = 0, statusQ = 0, statusP = 0, intime = 0;
		while (cases--) {
			int act, num;
			cin >> act >> num;
			if (act == 1) {
				Stack.push(num);
				Queue.push(num);
				Priority.push(num);
			}
			else {
				intime++;
				if(!Stack.empty())
					if (num == Stack.top()) {
						statusS++;
						Stack.pop();
					}
				if (!Queue.empty())
					if (num == Queue.front()) {
						statusQ++;
						Queue.pop();
					}
				if (!Priority.empty())
					if (num == Priority.top()) {
						statusP++;
						Priority.pop();
					}
			}
		}
		if ((intime == statusS && intime == statusQ) || (intime == statusS && intime == statusP) || (intime == statusQ && intime == statusP) || (intime == statusQ && intime == statusP && intime == statusS)) {
			cout << "not sure" << endl;
		}
		else if (intime == statusS) {
			cout << "stack" << endl;
		}
		else if (intime == statusQ) {
			cout << "queue" << endl;
		}
		else if (intime == statusP) {
			cout << "priority queue" << endl;
		}
		else {
			cout << "impossible" << endl;
		}
	}
	return 0;
}