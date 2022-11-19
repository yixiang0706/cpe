#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
int main() {
	int N, S, Q, set;
	cin >> set;
	vector<queue<int>>station;
	while (set--) {
		cin >> N >> S >> Q;
		station.clear();
		int cases,number;
		int Nreplace = N;
		while (Nreplace--) {
			cin >> cases;
			queue<int>temp;
			while (cases--) {
				cin >> number;
				temp.push(--number);
			}
			station.push_back(temp);
		}

		int currentStation = 0;
		int time = 0;
		stack<int> car;
		while (1) {
			while (!car.empty() && (station[currentStation].size() < Q || car.top() == currentStation)) {
				if (car.top() == currentStation)
					car.pop();
				else {
					station[currentStation].push(car.top());
					car.pop();
				}
				time++;
			}

			while (!station[currentStation].empty() && car.size() < S) {
				car.push(station[currentStation].front());
				station[currentStation].pop();
				time++;
			}//put station's object to car,time++.
			int cases = 0;
			for (int i = 0; i < station.size(); i++) {
				if (!station[i].empty() || !car.empty())
				{
					time += 2;
					break;
				}
				else
					cases++;
			}

			currentStation++;
			currentStation %= N;
			
			if (cases == station.size())
				break;
			/*for (int i = 0; i < station.size(); i++) {
				cout << station[i].size() << " ";
			}
			cout << endl;*/
		}
		cout << time << endl;
	}
}