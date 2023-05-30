#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void	make_dir_vector(vector<pair<int, int> > &dir) {
	dir.push_back(make_pair(-1, 0));
	dir.push_back(make_pair(0, 1));
	dir.push_back(make_pair(1, 0));
	dir.push_back(make_pair(0, 1));
}

pair<int, int>	run_bfs(int **drawingPaper, pair<int, int> node, unordered_set<pair<int, int> > &visited) {
	queue<pair<int, int> > node_queue;
	node_queue.push(node);
	pair<int, int> popped;
	vector<pair<int, int> > dir;
	vector<pair<int, int> >::iterator vec_iter;
	pair<int, int> answer;

	make_dir_vector(dir);
	vec_iter = dir.begin();
	answer = make_pair(1, 0);
	unordered_set<pair<int, int> > ::iterator iter;
	while (!(node_queue.empty())) {
		popped = node_queue.front();
		node_queue.pop();
		for (vec_iter=dir.begin();vec_iter != dir.end();vec_iter++) {
			try {
				if (drawingPaper[popped.first + vec_iter->first][popped.second + vec_iter->second]) {
					iter = visited.find(popped);
					if (iter != visited.end()) {
						node_queue.push(make_pair(popped.first + vec_iter->first, popped.second + vec_iter->second));
						answer.second += 1;
					}
				}
			}
			catch (int index) {
				continue;
			}
		}
	}
	return answer;
}

pair<int, int>	arrayCircuit(int **drawingPaper, int n, int m) {
	pair<int, int> loc;
	pair<int, int> answer;
	unordered_set<pair<int, int> > visited;

	pair<int, int> temp;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			loc = make_pair(i, j);
			visited.insert(loc);
			if (drawingPaper[loc.first][loc.second]) {
				temp = run_bfs(drawingPaper, loc, visited);
				answer.first += temp.first;
				answer.second += temp.second;
			}
		}
	}
	return answer;
}

int main() {
	int n, m;
	
	cin >> n >> m;
	int **drawingPaper;
	drawingPaper = new int *[n];
	for (int i = 0;i < n;i++)
	{
		drawingPaper[i] = new int[m];
		int temp;
		for (int j = 0;j < m;j++)
			drawingPaper[i][j] = scanf("%d", &temp);
	}
	pair<int, int> answer;
	answer = arrayCircuit(drawingPaper, n, m);
	printf("%d\n%d", answer.first, answer.second);
	for (int i = 0;i < n;i++)
		delete[] drawingPaper[i];
	delete drawingPaper;
}