#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<vector<int>> graph(150);
vector<int>d, low;
#define p pair<int,int>
set<pair<int, int>> result;
int times;
void dfs(int curpoint,int parent) {
	times++;
	d[curpoint] = times;
	low[curpoint] = times;
	for (auto it = graph[curpoint].begin(); it != graph[curpoint].end();it++) {
		if (d[*it] == 0) {
			dfs(*it,curpoint);
			low[curpoint] = min(low[curpoint], low[*it]);
			if (low[*it] > d[curpoint]) {
				p tmp = { min(curpoint, *it), max(curpoint, *it) };
				result.insert(tmp);
			}
		}
		else if (*it != parent)
			low[curpoint] = min(low[curpoint],d[*it]);
		
	}
}

int main() {
	int cases;
	while (cin >> cases) {
		graph.assign(cases,vector<int>());
		for (int i = 0; i < cases; i++) {
			int a, b;
			int n;
			char temp;
			cin >> a >> temp >> n >> temp;
			while (n--) {
				cin >> b;
				graph[a].push_back(b);
			}
		}

		times = 0;
		d.assign(cases, 0);
		low.assign(cases, 0);
		result.clear();
		for (int i = 0; i < cases; i++)
			if (d[i] == 0)
				dfs(i,-1);

		cout << result.size() << " critical links" << endl;
		for (auto it = result.begin(); it != result.end();it++) {
			cout << (*it).first << " - " << (*it).second << endl;
		}
		cout << endl;
	}
}