#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

#define VISIT 1
#define NOVISIT 0

int **visited;
int **maze;

int	run_bfs(int n, int m, pair<int, int> loc) {
	queue <pair <pair <int, int>, int> > node;
	pair<pair <int, int>, int> position;
	int	min = n * m;

	int	dir_row[4] = {-1, 0, 1, 0};
	int	dir_col[4] = {0, -1, 0, 1};
	int	x_p_dir;
	int	y_p_dir;

	node.push(make_pair(loc, 1));
	while (!node.empty()) {
		position = node.front();
		if (position.first.first == n - 1 && position.first.second == m - 1)
			return position.second;
		node.pop();
		for (int i = 0;i < 4;i++) {
			y_p_dir = position.first.first + dir_row[i];
			x_p_dir = position.first.second + dir_col[i];
			if (x_p_dir < 0 || y_p_dir < 0 || x_p_dir >= m || y_p_dir >= n)
				continue;
			if (maze[y_p_dir][x_p_dir] && !visited[y_p_dir][x_p_dir]) {
				node.push(make_pair(make_pair(y_p_dir, x_p_dir), position.second + 1));
			}
			visited[y_p_dir][x_p_dir] = VISIT;
		} 
	}
	return position.second;
}

int main() {
	int n, m;
	
	cin >> n >> m;
	maze = new int *[n];
	visited = new int *[n];
	for (int i = 0;i < n;i++) {
		maze[i] = new int[m];
		visited[i] = new int[m];
		for (int j = 0;j < m;j++) {
			scanf("%1d", &maze[i][j]);
			visited[i][j] = 0;
		}
	}
	cout << run_bfs(n, m, make_pair(0, 0));
}