#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <map>
#include <utility>
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;

//1911

void heapify(vector<pair<int, int> >& arr, int n, int i) 
{
	int largest = i; // 부모 노드
	int left = 2 * i + 1; // 왼쪽 자식 노드
	int right = 2 * i + 2; // 오른쪽 자식 노드

	if (left < n && arr[left] > arr[largest])
		largest = left; // 왼쪽 자식이 부모보다 크면, 가장 큰 노드가 왼쪽 자식

	if (right < n && arr[right] > arr[largest])
		largest = right; // 오른쪽 자식이 부모보다 크면 가장 큰 노드가 오른쪽 자식

	if (largest != i) // 가장 큰 노드가 초기값이 아니면(바꼈으면)
    {
		swap(arr[i], arr[largest]); // 노드를 바꿔줌(largest는 left아니면 right)
		heapify(arr, n, largest); // 하향으로 계속해서 재귀
	}
}

void heapSort(vector<pair<int, int> >& arr) 
{
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; --i) // size에 2 나누고 1빼면 뿌리 노드의 부모가 됨 
		heapify(arr, n, i); // 부모 노드가 0번째가 될때까지 계속 진행

	for (int i = n - 1; i > 0; --i) 
    {
		swap(arr[0], arr[i]); // 제일 큰 값을 제일 마지막 인덱스로 하나씩 보내주면서
		heapify(arr, i, 0); // 위 과정을 반복하면 최소 힙이 된다
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	int ans = 0;
	vector<pair<int, int> > mud;

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		mud.push_back(make_pair(start, end));
	}

	heapSort(mud);

	int idx = 0;

	for (int i = 0; i < N; i++) {
		if (idx >= mud[i].second)
			continue;

		idx = max(idx, mud[i].first);

		int cnt = (mud[i].second - (idx + 1)) / L + 1;
		ans += cnt;
		idx += L * cnt;
	}

	cout << ans << '\n';

	return 0;
}
