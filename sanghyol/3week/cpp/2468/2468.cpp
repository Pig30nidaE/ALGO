#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int **area;
int **visited;

void	run_dfs(pair<int, int> loc, int prcpt, int n) {
	vector <pair <int, int> > pan;
	pan.push_back(make_pair(0, 1));
	pan.push_back(make_pair(1, 0));
	pan.push_back(make_pair(0, -1));
	pan.push_back(make_pair(-1, 0));
	for (pair <int, int> dir : pan) {
		pair <int, int> posi = make_pair(loc.first + dir.first, loc.second + dir.second);
		if (posi.first < 0 || posi.second < 0 || posi.first >= n || posi.second >= n)
			continue;
		if (area[posi.first][posi.second] > prcpt && !visited[posi.first][posi.second]) {
			visited[posi.first][posi.second] = 1;
			run_dfs(posi, prcpt, n);
		}
	}
}

int	get_safety_area(int prcpt, int n) {
	int	count = 0;
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++)
			visited[i][j] = 0;
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (!visited[i][j] && area[i][j] > prcpt) {
				count++;
				visited[i][j] = 1;
				run_dfs(make_pair(i, j), prcpt, n);
			}
		}
	}
	return count;
}

int main() {
	int max = 0;
	int n;
	cin >> n;

	area = new int *[n];
	visited = new int *[n];
	for (int i = 0;i < n;i++) {
		area[i] = new int [n];
		visited[i] = new int [n];
		for (int j = 0;j < n;j++) {
			scanf("%d", &area[i][j]);
			if (area[i][j] > max)
				max = area[i][j];
		}
	}
	int answer = 0;
	int result;
	for (int precipitation = 0;precipitation < max;precipitation++) {
		result = get_safety_area(precipitation, n);
		if (result > answer)
			answer = result;
	}
	cout << answer;
}