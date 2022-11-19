#include<iostream>
#include<queue>
#include<string>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		string curSide = "left";//left=0,right=1
		int n, t, m;
		cin >> n >> t >> m;
		//n boat container
		//t the time to opposite bank
		//m car numbers
		queue<int>arrivalTimeL, arrivalTimeR;
		queue<int>NoL, NoR;
		int time;
		string tmp;
		for (int i = 0; i < m; i++) {
			cin >> time >> tmp;
			if (tmp == "left") {
				arrivalTimeL.push(time);
				NoL.push(i);
			}
			else {
				arrivalTimeR.push(time);
				NoR.push(i);
			}
		}
		
		int realTime=0;
		int j = 0;
		int curNO = 0;
		int temp[10000] = {};
		while (!arrivalTimeL.empty() || !arrivalTimeR.empty()) {
			int minTime;
			if (arrivalTimeL.empty())minTime = arrivalTimeR.front();
			else if (arrivalTimeR.empty())minTime = arrivalTimeL.front();
			else if (arrivalTimeL.front() == 0 || arrivalTimeR.front() == 0)
				minTime = 0;
			else {
				if (arrivalTimeL.front() > arrivalTimeR.front())
					minTime = arrivalTimeR.front();
				else
					minTime = arrivalTimeL.front();
			}

			if (realTime < minTime)
				realTime = minTime;

			bool status = 0;
			if (curSide == "left") {
				if (!arrivalTimeL.empty())
					if (arrivalTimeL.front() <= realTime) 
						for (j = 1; j <= n; j++) {
							status = 1;
							arrivalTimeL.pop();
							temp[NoL.front()] = realTime + t;
							NoL.pop();
							if (arrivalTimeL.empty() || arrivalTimeL.front() > realTime)
								break;
						}
			}
			else {
				if (!arrivalTimeR.empty())
					if (arrivalTimeR.front() <= realTime) 
						for (j = 1; j <= n; j++) {
							status = 1;
							arrivalTimeR.pop();
							temp[NoR.front()] = realTime + t;
							NoR.pop();
							if (arrivalTimeR.empty() || arrivalTimeR.front() > realTime)
								break;
						}
			}

			if (curSide == "left" && (!arrivalTimeR.empty() || j != 0)) {
				curSide = "right";
			}
			else if(curSide == "right" && (!arrivalTimeL.empty() || j != 0)) {
				curSide = "left";
			}
			realTime += t;
			j = 0;
		}

		for (int i = 0; i < m; i++) {
				cout << temp[i] << endl;
		}
		if(cases)
			cout << endl;
	}
}