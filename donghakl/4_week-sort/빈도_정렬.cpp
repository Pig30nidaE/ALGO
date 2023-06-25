#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

map<long, int> order;
bool cmp(pair<long, int>& a, pair<long, int>& b)
{
	if (a.second == b.second)
		return order[a.first] < order[b.first];

	return a.second > b.second;
}


void select_sort(vector <pair<long, int > > *v, map<long, int> *arr, int c_size)
{
	int key;
	int value;
	int index;
	for (int i = 0; i < c_size - 1; i++)
	{
		key = (*v)[i].first;
		value = (*v)[i].second;
		index = i;
		for (int j = i + 1; j < c_size; j++)
		{
			// if (value < (*v)[j].first)
			// {
			// 	value = (*v)[j].first;
			// 	key = (*v)[j].second;
			// 	index = j;
			// }
			if (value == (*v)[j].second)
			{
				if ((*arr)[key] > (*arr)[(*v)[j].first])
				{
					swap((*v)[index], (*v)[j]);
				}
			}
		}
		// swap((*v)[i], (*v)[index]);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long c, tmp;
	cin >> n >> c;
	map<long, int> dic;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		dic[tmp]++;
		if (order[tmp] == 0)
			order[tmp] = i+1;
	}
	
	// vector<pair<long, int> > v(dic.begin(), dic.end());
	vector<pair<long, int> > v(dic);
	
	int v_size = v.size(); 

	sort(v.begin(), v.end(), cmp);
	// select_sort(&v, &order, v.size());

	int cnt, key;
	for (int i = 0; i < v_size; i ++)
	{
		key = v[i].first;
		cnt = v[i].second;
		for (int j = 0; j < cnt; j ++)
		{
			cout << key << " ";
		}
	}
	cout << "\n";
}