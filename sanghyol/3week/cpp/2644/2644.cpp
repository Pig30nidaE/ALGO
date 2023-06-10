#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

map <int, vector<int> > family;
map <int, int> family_reverse;

int	run_dfs(int node, int target, int depth, vector<int> *path) {
	map<int, vector<int> >::iterator parent_iter;
	vector<int>::iterator child_iter;

	parent_iter = family.find(node);
	if (parent_iter != family.end()) {
		(*path).insert((*path).begin(), parent_iter->first);
		child_iter = parent_iter->second.begin();
		for (child_iter = parent_iter->second.begin();child_iter != parent_iter->second.end();child_iter++) {
			if (*child_iter == target)
				return depth;
			else 
				return run_dfs(*child_iter, target, depth + 1, path);
		}
		return depth;
	}
	else
		return depth;
}

int main() {
	int n;
	int target1, target2;
	int m;

	cin >> n;
	cin >> target1 >> target2;
	cin >> m;
	for (int i = 0;i < m;i++) {
		int parent, child;
		scanf("%d %d", &parent, &child);
		family[parent].push_back(child);
		family_reverse[child] = parent;
	}
	vector <int> path1;
	vector <int> path2;
	vector<int>::iterator path1_iter;
	vector<int>::iterator path2_iter;
	int answer1 = run_dfs(1, target1, 1, &path1);
	int answer2 = run_dfs(1, target2, 1, &path2);
	// path1_iter = path1.begin();
	// path2_iter = path2.begin();
	
	int count = 0;
	// while (*path1_iter == *path2_iter
	// 	&& (path1_iter != path1.end() && path2_iter != path2.end())) {
	// 		count++;
	// 		path1_iter++;
	// 		path2_iter++;
	// }
	while ((path1[count] && path2[count]) && path1[count] == path2[count])
		count++;
	if (!count)
		cout << -1;
	else
		cout << answer1 + answer2 - count;
}