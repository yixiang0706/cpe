#include<iostream>
#include<vector>
using namespace std;
int dfs(vector<vector<int>>& graph, vector<int>& visited, int point) {
	int visitnumber = 0;
	for (int i = 0; i < graph[point].size(); i++) {
		if (visited[graph[point][i]] == false) {
			visitnumber++;
			visited[graph[point][i]] = true;
			visitnumber += dfs(graph, visited, graph[point][i]);
		}
	}
	return visitnumber;
}
int main() {
	int n;
	while (cin >> n, n != 0) {
		vector<vector<int>> graph(150);
		int vertex_i,vertex_n;
		while (cin >> vertex_i, vertex_i != 0) {
			while (cin >> vertex_n, vertex_n != 0) {
				graph[vertex_i].push_back(vertex_n);
			}
		}
		int point,number;
		cin >> number;
		for (int i = 0; i < number; i++) {
			cin >> point;
			vector<int> visited(150, false);
			int unvisited = n - dfs(graph,visited,point);
			cout << unvisited;
			for (int i = 1; i <= n; i++) {
				if (visited[i] == false) {
					cout << " " << i ;
				}
			}
			cout << endl;
		}
	}

	
}