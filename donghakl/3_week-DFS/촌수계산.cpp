#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, target1, target2, m, x, y;
// n -> 전체 사람, m -> 관계 수
// int DFS(vector <int > map[], int *visit[], int cur, int depth, int parent, int target1, int target2)
// {
// 	if ((visit)[cur][1] != 0)
// 		return (0);
// 	if (cur != 1)
// 		visit[cur][0] = parent;
// 	visit[cur][1] = depth;

// 	for (int i = 0; i < map[cur].size(); i++)
// 	{
// 		if (cur == 1)
// 			parent++;
// 		DFS(map, visit, map[cur][i], depth + 1, parent, target1, target2);
// 	}
// 	return (depth);
// }

int DFS(vector <int > map[], int *visit, int target1, int target2, int depth, int *result)
{
	if (visit[target1] != 0)
		return (0);

	visit[target1] = 1;
	if (target1 == target2)
	{
		*result = depth;
		return depth;
	}

	for (int i = 0; i < map[target1].size(); i++)
	{
		DFS(map, visit, map[target1][i], target2, depth + 1, result);
	}
	return (depth);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> target1 >> target2 >> m;

	int *visit = new int [n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		visit[i] = 0;
	}

	vector <int > map [n + 1];

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}

	int result = -1;
	DFS(map, visit, target1, target2, 0, &result);
	cout << result << "\n";

	// if (visit[target1][0] != visit[target2][0])
	// {

	// 	if (((visit[target1][0] == 0 && visit[target1][1] == 0) || (visit[target2][0] == 0 && visit[target2][1] == 0)) && (visit[target1][1] == 1 || visit[target2][1] == 1))
	// 	{
	// 		cout << "1\n";
	// 	}
	// 	else if ((visit[target1][0] == 0 && visit[target1][1] == 0) || (visit[target2][0] == 0 && visit[target2][1] == 0))
	// 		cout << "-1\n";
	// 	else
	// 		cout << visit[target1][1] + visit[target2][1] << "\n";
	// }
	// else if (visit[target1][1] != visit[target2][1])
	// {
	// 	if (visit[target1][1] < visit[target2][1])
	// 		cout << visit[target2][1] - visit[target1][1] << "\n";
	// 	else
	// 		cout << visit[target1][1] - visit[target2][1] << "\n";
	// }
	// else if ((target1 != 1 && visit[target1][0] == 0 && visit[target1][1] == 0) || (target2 != 1 && visit[target2][0] == 0 && visit[target2][1] == 0))
	// {
	// 	cout << "-1\n";
	// }
	// else
	// {
	// 	cout << "2\n";
	// }

	delete [] visit;
}