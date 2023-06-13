#include <map>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

map <int, vector<int> > family;
map <int, int> family_reverse;
int flag = 0;

void	run_dfs(int node, int target, vector<int> *path) {
	map <int, vector <int> >::iterator parent_iter;
	(*path).insert((*path).begin(), node);
	if (node == target) {
		flag = 1;
		return ;
	}
	parent_iter = family.find(node);
	if (parent_iter == family.end())
		return ;
	vector <int>::iterator child_iter;
	child_iter = parent_iter->second.begin();
	for (child_iter = parent_iter->second.begin();
		child_iter != parent_iter->second.end();child_iter++) {
		run_dfs(*child_iter, target, path);
		if (flag)
			return ;
		(*path).erase((*path).begin());
	}
	return ;
}

int	get_root_node(int target) {
	while (family_reverse[target])
		target = family_reverse[target];
	return target;
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
	int target1_root = get_root_node(target1);
	int target2_root = get_root_node(target2);
	if (target1_root != target2_root) {
		cout << -1;
		return 0;
	}
	run_dfs(target1_root, target1, &path1);
	flag = 0;
	run_dfs(target2_root, target2, &path2);
	int count = 0;
	path1_iter = path1.end() - 1;
	path2_iter = path2.end() - 1;
	while (*path1_iter && *path2_iter && *path1_iter == *path2_iter) {
		count++;
		path1_iter--;
		path2_iter--;
	}
	cout << path1.size() + path2.size() - count * 2;
}