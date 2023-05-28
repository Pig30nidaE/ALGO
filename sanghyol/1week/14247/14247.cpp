#include <iostream>
#include <map>
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
	map<int, int> A;
	int	n;

	cin >> n;
	int	H[n];
	int	temp;
	for (int i = 0;i < n;i++) {
		cin >> H[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> A[i];
	}
	vector <pair<int, int>> A_vec(A.begin(), A.end()); // 길이가 증가하는 정보를 vector로 변환
	sort(A_vec.begin(), A_vec.end(), cmp); // 증가하는 순위에 따라 정렬
	long long cost = 0;
	long long i = 0;
	for (auto k:A_vec) {
		cost += H[k.first] + (k.second * i); // 증가하는 순위 별로 더함
		i++;
	}
	cout << cost;
	return 0;
}
