#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

#define VISIT 1
#define NOVISIT 2

int	**farm;
int	**visited;

void run_bfs(int n, int m, pair<int, int> loc) {
	queue <pair <int, int> > node;
	pair <int, int> position;

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
            if (farm[y_p_dir][x_p_dir] && !visited[y_p_dir][x_p_dir])
                node.push(make_pair(y_p_dir, x_p_dir));
            visited[y_p_dir][x_p_dir] = VISIT;
        }
    }
}

int main() {
    int t;
    int m, n, k;
    int x, y;
    int count;
    cin >> t;
    for (int i = 0;i < t;i++) {
        cin >> m >> n >> k;
        farm = new int *[n];
        visited = new int *[n];
        count = 0;
        for (int j = 0;j < n;j++) {
            farm[j] = new int [m];
            visited[j] = new int [m];
            for (int w = 0;w < m;w++) {
                farm[j][w] = 0;
                visited[j][w] = 0;
            }
        }
        for (int j = 0;j < k;j++) {
            scanf("%d %d", &x, &y);
            farm[y][x] = 1;
        }
        for (int j = 0;j < n;j++) {
            for (int w = 0;w < m;w++) {
                if (farm[j][w]) {
                    if (!visited[j][w]) {
                        count++;
                        run_bfs(n, m, make_pair(j, w));
                    }
                }
                visited[j][w] = VISIT;
            }
        }
        cout << count << '\n';
        for (int j = 0;j < n;j++) {
            delete[] farm[j];
            delete[] visited[j];
        }
        delete farm;
        delete visited;
    }
}