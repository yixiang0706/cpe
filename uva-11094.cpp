#include<iostream>
using namespace std;
char matrix[21][21];
int visited[21][21];
int row, col;
char target;
int number;
void dfs(int sx, int sy) {
	visited[sx][sy] = true;
	number++;
	int ox, oy;
	//left
		ox = sx;
		oy = sy - 1;
		if (oy < 0)oy = col - 1;
		if (visited[ox][oy] == false && matrix[ox][oy] == target)
			dfs(ox, oy);
	
	//up
		ox = sx - 1;
		oy = sy;
		if (ox >= 0 && visited[ox][oy] == false && matrix[ox][oy] == target)
			dfs(ox, oy);
	
	//right
		ox = sx;
		oy = sy + 1;
		if (oy >= col)oy = 0;
		if (visited[ox][oy] == false && matrix[ox][oy] == target)
			dfs(ox, oy);
	
	//down
		ox = sx + 1;
		oy = sy;
		if (ox <= row - 1 && visited[ox][oy] == false && matrix[ox][oy] == target)
			dfs(ox, oy);
	
}
int main() {
	while (cin >> row >> col) {
		char s;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> s;
				visited[i][j] = false;
				matrix[i][j] = s;
			}
		}

		int sx, sy;
		cin >> sx >> sy;
		number = 0;
		target = matrix[sx][sy];
		dfs(sx, sy);

		int max = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (visited[i][j] == false && matrix[i][j] == target) {
					number = 0;
					dfs(i, j);
					if (number > max)
						max = number;
				}
			}
		}

		cout << max << endl;
	}
	return 0;
}