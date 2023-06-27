#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[21][21];

int cmp(string text1, string text2)
{
	if (text1 < text2)
		return 1;
	else if (text1 > text2)
		return 2;
	else
		return 0;
}

void makeheap(vector <string> *vec, int root, int n)
{

	string temp_fir = (*vec)[root]; // root->부모 노드
	int child = root * 2; // 왼쪽 자식 노드
	while (child <= n)
	{ // 더 큰 자식 노드 찾기
		if (child < n && cmp((*vec)[child], (*vec)[child + 1]) == 1)
			child++;
		if (cmp(temp_fir, (*vec)[child]) == 1)
		{
			swap((*vec)[child/2], (*vec)[child]);
			child *= 2;
		}
		else
			break;
	}
	(*vec)[child/2] = temp_fir;
}

void heapsort(vector <string> *vec, int n) // n -> 마지막 인덱스
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
	string tmp;

	int r, c;
	cin >> r >> c;
	string *str = new string[r];
	for (int i = 0; i < r; i++)
	{
	
		cin >> tmp;
		str[i] = tmp;

	}

	int index;
	int value;
	int min = 'z';
	int tmp2;
	vector <string> vec;
	string word;
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (str[j][i] == '#')
			{
				if (word.length() > 1)
				{
					vec.push_back(word);
				}
				word.clear();
			}
			else
			{
				word.push_back(str[j][i]);
			}
		}
		if (word.length() > 1)
		{
			vec.push_back(word);
		}
		word.clear();
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (str[i][j] == '#')
			{
				if (word.length() > 1)
				{
					vec.push_back(word);
				}
				word.clear();
			}
			else
			{
				word.push_back(str[i][j]);
			}
		}
		if (word.length() > 1)
		{
			vec.push_back(word);
		}
		word.clear();
	}
	sort(vec.begin(), vec.end());
	heapsort(&vec, vec.size() - 1);


	cout << vec[0] << "\n";
}