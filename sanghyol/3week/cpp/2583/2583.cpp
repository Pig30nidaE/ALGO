#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int	**rectangle;
int	**visited;

int	run_dfs(pair<int, int> loc, int m, int n, int size) {
	vector <pair <int, int> > pan;
	pan.push_back(make_pair(0, 1));
	pan.push_back(make_pair(1, 0));
	pan.push_back(make_pair(0, -1));
	pan.push_back(make_pair(-1, 0));
	for (pair <int, int> dir : pan) {
		pair <int, int> posi = make_pair(loc.first + dir.first, loc.second + dir.second);
		if (posi.first < 0 || posi.second < 0 || posi.first >= m || posi.second >= n)
			continue;
		if (!rectangle[posi.first][posi.second] && !visited[posi.first][posi.second]) {
			visited[posi.first][posi.second] = 1;
			size = run_dfs(posi, m, n, size + 1);
		}
	}
	return size;
}

pair <int, vector <int> > get_rec_info(int m, int n) {
	int count = 0;
	vector <int> size;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (!visited[i][j] && !rectangle[i][j]) {
				count++;
				visited[i][j] = 1;
				size.push_back(run_dfs(make_pair(i, j), m, n, 1));
			}
		}
	}
	return make_pair(count, size);
}

int main() {
	int m, n, k;

	cin >> m >> n >> k;
	rectangle = new int *[m];
	visited = new int *[m];
	for (int i = 0;i < m;i++) {
		rectangle[i] = new int [n];
		visited[i] = new int [n];
		memset(rectangle[i], 0, n);
		memset(visited[i], 0, n);
	}
	for (int i = 0;i < k;i++) {
		int lx, ly, rx, ry;
		scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
		while  (ly < ry) {
			int temp = lx;
			while (temp < rx) {
				rectangle[ly][temp] = 1;
				temp++;
			}
			ly++;
		}
	}
	pair <int, vector <int> > answer;
	answer = get_rec_info(m, n);
	cout << answer.first << '\n';
	sort(answer.second.begin(), answer.second.end());
	for (int size : answer.second)
		cout << size << ' ';
}