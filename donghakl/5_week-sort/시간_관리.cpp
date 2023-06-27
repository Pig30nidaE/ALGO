#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void makeheap(vector <pair <int, int > > *vec, int root, int n)
{

	int temp_fir = (*vec)[root].first; // root->부모 노드
	int temp_sec = (*vec)[root].second; // root->부모 노드
	int child = root * 2; // 왼쪽 자식 노드
	while (child <= n)
	{ // 더 큰 자식 노드 찾기
		if (child < n && (*vec)[child].first < (*vec)[child + 1].first)
			child++;
		if (temp_fir < (*vec)[child].first)
		{
			(*vec)[child/2].first = (*vec)[child].first;
			(*vec)[child/2].second	= (*vec)[child].second;
			child *= 2;
		}
		else
			break;
	}
	(*vec)[child/2].first = temp_fir;
	(*vec)[child/2].second = temp_sec;
}

void heapsort(vector <pair <int, int > > *vec, int n) // n -> 마지막 인덱스
{
	for (int i = n/2; i > 0; i--)
	{
		makeheap(vec, i, n);
	}

	for (int i =n; i > 0; i--)
	{
		swap((*vec)[1], (*vec)[i]);
		makeheap(vec, 1, i - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, fir, sec;
	cin >> n;
	vector <pair <int, int > > vec;

	vec.push_back(make_pair(-1 , -1));
	for (int i = 0; i < n; i++)
	{
		cin >> sec >> fir;
		vec.push_back(make_pair(fir, sec));
	}

	heapsort(&vec, n);

	int run_time = 0;
	int finish_time = 0;
	int free_time = 0;
	int i = 0;
	for (free_time = 0; free_time <= vec[1].first - vec[1].second; free_time++)
	{
		run_time = free_time;
		for (i = 1; i < n + 1; i++)
		{
			run_time += vec[i].second;
			finish_time = vec[i].first;
			if (run_time > finish_time)
			{
				if (free_time == 0)
				{
					cout << "-1\n";
					return 0;
				}
				break;
			}
		}
		if (i != n + 1)
			break;
	}
	cout << free_time - 1;
}