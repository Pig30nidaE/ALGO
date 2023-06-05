#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define VISIT 1
#define NOVISIT 2

int	**drawingPaper;
int	**visited;

int	run_bfs(int n, int m, pair<int, int> loc) {
	queue <pair <int, int> > node;
	pair <int, int> position;

	int	size = 1;
	int	dir_row[4] = {-1, 0, 1, 0};
	int	dir_col[4] = {0, -1, 0, 1};
	int	x_p_dir;
	int	y_p_dir;

	node.push(loc);
	while (!node.empty()) {
		position = node.front();
		node.pop();
		for (int i = 0;i < 4;i++) {
			y_p_dir = position.first + dir_row[i];
			x_p_dir = position.second + dir_col[i];
			if (x_p_dir < 0 || y_p_dir < 0 || x_p_dir >= m || y_p_dir >= n)
				continue;
			if (drawingPaper[y_p_dir][x_p_dir] && !visited[y_p_dir][x_p_dir]) {
				size++;
				node.push(make_pair(y_p_dir, x_p_dir));
			}
			visited[y_p_dir][x_p_dir] = VISIT;
		} 
	}
	return size;
}

pair <int, int>	circuit_arr(int n, int m) {
	int count = 0;
	int	bfs_res = 0;
	int	max = 0;

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			if (drawingPaper[i][j]) {
				if (drawingPaper[i][j] && !visited[i][j]) {
					count++;
					visited[i][j] = VISIT;
					bfs_res = run_bfs(n, m, make_pair(i, j));
					if (bfs_res > max)
						max = bfs_res;
				}
			}
		}
	}
	return make_pair(count, max);
}

int main() {
	int n, m;

	cin >> n >> m;
	drawingPaper = new int *[n];
	visited = new int *[n];
	for (int i = 0;i < n;i++) {
		drawingPaper[i] = new int [m];
		visited[i] = new int [m];
		for (int j = 0;j < m;j++) {
			scanf("%d", &drawingPaper[i][j]);
			visited[i][j] = 0;
		}
	}

	pair <int, int> answer;
	answer = circuit_arr(n, m);
	cout << answer.first << '\n' << answer.second;

}