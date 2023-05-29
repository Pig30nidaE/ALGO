
// 위		: 16, 14, 13 ,15

// 오른쪽   : 6, 16, 15, 14

// 밑		: 16, 14, 13, 15

// 왼쪽쪽	 : 6, 16, 15, 14

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long column, row;
	long total = 0;
	cin >> row >> column;

	vector<vector<long> > arr(row, vector<long>(column, 0));
	vector<long> front(column, 0);
	vector<long> side(row, 0);

	long tmp;

	for (long i = 0; i < row; i++)
	{
		tmp = 0;
		for (long j = 0; j < column; j++)
		{
			cin >> arr[i][j];
			total += arr[i][j];
			if (tmp < arr[i][j])
			{
				tmp = arr[i][j];
			}
		}
		side[i] = tmp;
	}

	for (long i = 0; i < column; i++)
	{
		tmp = 0;
		for (long j = 0; j < row; j++)
		{
			if (tmp < arr[j][i])
			{
				tmp = arr[j][i];
			}
		}
		front[i] = tmp;
	}
	vector<long> v(front);
	v.insert(v.end(), side.begin(), side.end());
	long flag = 0;
	long result = 0;
	sort(v.begin(), v.end());
	for (long i = 0; i < (column + row); i++)
	{
		if (flag != v[i])
		{
			// printf("!!%d\n", v[i]);
			result += v[i];
			flag = v[i];
		}
	}

	cout << total - result;

	// // tester
	// cout << endl;
	// for (int i = 0; i < row; i++)
	// {
	// 	for (int j = 0; j < column; j++)
	// 	{
	// 		cout << arr[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	// cout << "side: ";
	// for (int i = 0; i < column; i++)
	// {
	// 	cout << side[i] << " ";
	// }
	// cout << endl;

	// cout << "front: ";
	// for (int i = 0; i < column; i++)
	// {
	// 	cout << front[i] << " ";
	// }
	// cout << endl;
}