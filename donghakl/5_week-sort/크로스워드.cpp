#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[21][21];

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
	vector <pair <int, int > > vec;
	for (int i = 0; i < r; i++)
	{
		if (i == 0 || i ==  r - 1)
		{
			for (int j = 0; j < c; j++)
			{
				tmp2 = (int)str[i][j];
				if (tmp2 == '#')
					continue;
				if (min >= tmp2)
				{
					if (min == tmp2)
					{
						vec.push_back(make_pair(i, j));
						continue;
					}
					min = tmp2;
					vec.clear();
					vec.push_back(make_pair(i, j));
				}
			}
		}
		else
		{
			tmp2 = (int)str[i][0];
			if (tmp2 == '#')
				continue;
			if (min >= tmp2)
			{
				if (min == tmp2)
				{
					vec.push_back(make_pair(i, 0));
				}
				else
				{
					min = tmp2;
					vec.clear();
					vec.push_back(make_pair(i, 0));
				}
			}
			tmp2 = (int)str[i][c-1];
			if (tmp2 == '#')
				continue;
			if (min >= tmp2)
			{
				if (min == tmp2)
				{
					vec.push_back(make_pair(i, c-1));
				}
				else
				{
					min = tmp2;
					vec.clear();
					vec.push_back(make_pair(i, c-1));
				}
			}
		}
	}

	int x=-1, y=-1;
	for (vector <pair<int, int> >::iterator i = vec.begin(); i != vec.end(); i++)
	{
		x = i->second;
		y = i->first;
		if ((y == 0 && x == 0) || (y == r-1 && x == 0) || (y == 0 && x == c-1) || (y == r-1 && x == c-1))
		{


		}
		else
		{

		}
		
		printf("%d, %d\n", i->first, i->second);
	}

	for (int i = 0; i < r; i++)
	{
		cout << str[i][0] << "\n";
	}
	delete [] str;
}