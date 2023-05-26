#include <iostream>
#include <stdio.h>
#include <map>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define INC_VAL 0
#define CURR_VAL 1
#define USED_FLAG 2

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main(){
	map<int, int> increase_info;
	int	n;

	scanf("%d", &n);
	vector <int> HA[n];
	int	temp;
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		HA[i] = vector <int> {temp};
	}
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);
		increase_info[i] = temp;
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			HA[i].push_back(HA[i][j] + increase_info[i]);
		}
	}
	vector <pair<int, int>> inc_info_vec(increase_info.begin(), increase_info.end());
	sort(inc_info_vec.begin(), inc_info_vec.end(), cmp);
	int cost = 0;
	int	i = 0;
	for (auto k:inc_info_vec) {
		cost += HA[k.first][i];
		i++;
	}
	cout << cost;
	return 0;
}
