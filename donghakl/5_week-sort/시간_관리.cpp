#include <iostream>
#include <algorithm>

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

	for (int i = 0; i < n + 1; i++)
	{
		printf("%d:%d\n", vec[i].first, vec[i].second);
	}

}