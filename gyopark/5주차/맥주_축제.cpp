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

// 17503
int N, M, K, V, C, sum;
// N 참가일자, M 선호도 합, K 총일자, V 선호도, C 도수; 
vector<pair<int, int> > beer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>N>>M>>K;
	for (int i = 0; i < K; i++)
	{
		cin>>V>>C;
		beer.push_back(make_pair(C, V));
	}

	sort(beer.begin(), beer.end());
	
	// for (int i = 0; i < K; i++)
	// {
	// 	cout<<beer[i].first<<' '<<beer[i].second<<'\n';
	// }

	priority_queue<int>pq;

	for (int i = 0; i < K; i++)
	{
		pq.push(-beer[i].second);
		sum += beer[i].second;
		if (pq.size() > N)
		{
			sum += pq.top();
			pq.pop();
		}
		if (pq.size() == N && sum >= M)
		{
			cout<<beer[i].first;
			return 0;
		}
	}
	cout<<"-1";
	return 0;
}