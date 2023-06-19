#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

int compare(vector<pair<pair<long long ,int>, int> > info, int target1, int target2) {
	vector<pair<pair<long long ,int>, int> >::iterator iter1;
	vector<pair<pair<long long ,int>, int> >::iterator iter2;
	for (iter1 = info.begin();iter1 != info.end();iter1++) {
		if (iter1->first.first == target1)
			break;
	}
	for (iter2 = info.begin();iter2 != info.end();iter2++) {
		if (iter2->first.first == target2)
			break;
	}
	if (iter1->first.second > iter2->first.second)
		return -1;
	if (iter1->first.second < iter2->first.second)
		return 1;
	if (iter1->second > iter2->second)
		return 1;
	if (iter1->second < iter2->second)
		return -1;
	return 0;
}

vector<pair<pair<long long ,int>, int> > insertion_sort(vector<pair<pair<long long ,int>, int> > info) {
	int size = info.size();
	for (int key_index = 1;key_index < size;key_index++) {
		for (int cmp_index = key_index - 1;cmp_index >= 0;cmp_index--) {
			if (compare(info, info[cmp_index].first.first, info[key_index].first.first) >= 0) {
				swap(info[key_index], info[cmp_index]);
				key_index = cmp_index;
			}
		}
	}
	return info;
}

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	int n;
	long long c;
	cin >> n >> c;

	if (n == 1) {
		long long temp;
		cin >> temp;
		cout << temp;
		return 0;
	}
	vector<pair<pair<long long ,int>, int> > info;
	vector<pair<pair<long long ,int>, int> >::iterator find_iter;
	int order = 0;
	for (int i = 0;i < n;i++) {
		int temp;
		cin >> temp;
		find_iter = info.begin();
		for (find_iter = info.begin();find_iter != info.end();find_iter++) {
			if (find_iter->first.first == temp)
				break;
		}
		if (find_iter == info.end()) {
			info.push_back(make_pair(make_pair(temp, 1), order));
			order++;
		}
		else
			find_iter->first.second++;
	}
	info = insertion_sort(info);
	for (find_iter = info.begin();find_iter != info.end();find_iter++) {
		for (int i = 0;i < find_iter->first.second;i++)
			cout << find_iter->first.first << ' ';
	}
}