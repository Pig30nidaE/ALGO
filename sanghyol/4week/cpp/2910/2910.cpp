#include <vector>
#include <set>
#include <iterator>
#include <iostream>
using namespace std;

int compare(vector<pair<pair<int ,int>, int> > info, int target1, int target2) {
	vector<pair<pair<int ,int>, int> >::iterator iter1;
	vector<pair<pair<int ,int>, int> >::iterator iter2;
	for (iter1 = info.begin();iter1 != info.end();iter1++) {
		if (iter1->first.first == target1)
			break;
	}
	for (iter2 = info.begin();iter2 != info.end();iter2++) {
		if (iter2->first.first == target2)
			break;
	}
	if (iter1->first.first > iter2->first.first)
		return -1;
	if (iter1->first.first < iter2->first.first)
		return 1;
	if (iter1->first.second > iter2->first.second)
		return 1;
	if (iter1->first.second < iter2->first.second)
		return -1;
	return 0;
}

vector<pair<pair<int ,int>, int> > insertion_sort(vector<pair<pair<int ,int>, int> > info) {
	vector<pair<pair<int ,int>, int> >::iterator key_iter;
	vector<pair<pair<int ,int>, int> >::iterator cmp_iter;
	key_iter = info.begin();
	key_iter++;
	while (key_iter != info.end()) {
		cmp_iter = key_iter;
		cmp_iter--;
		while (cmp_iter != info.begin()) {
			if (compare(info, key_iter->first.first, cmp_iter->first.first))
				swap(key_iter, cmp_iter);
			cmp_iter--;
		}
		key_iter++;
	}
	return info;
}

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

	int n, c;
	cin >> n >> c;

	if (n == 1) {
		int temp;
		cin >> temp;
		cout << temp;
		return 0;
	}
	vector<pair<pair<int ,int>, int> > info;
	vector<pair<pair<int ,int>, int> >::iterator find_iter;
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