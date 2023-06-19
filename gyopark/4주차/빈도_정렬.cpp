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

//2910

map<int, int> order;

int	cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return order[a.second] < order[b.second];
	return a.first > b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, c;
	cin>>n>>c;
	map<int, int> m;
	map<int, int>::iterator it;
	vector<pair<int, int> > v;
	vector<int> answer;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		m[num]++; // key가 num인 원소가 없을 때, 생성하고 value값을 1 더함
		if (order[num] == 0) // 일반 변수로 구성된 map의 경우 할당안된 값을 0으로 초기화
			order[num] = i + 1;
	}
 
	// m.first -> 숫자,  m.second -> 빈도
	for (it = m.begin(); it != m.end(); it++)
	{
		v.push_back(make_pair(it->second, it->first));
	}
	//v(3, 2) (2, 1)

	std::sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].first; j++)
			answer.push_back(v[i].second);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}

	return 0;
}