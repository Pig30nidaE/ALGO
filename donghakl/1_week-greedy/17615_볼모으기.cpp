#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	long n;
	long left_len = 0;
	int left_color = 0;
	long right_len = 0;
	int right_color = 0;

	long red_total = 0;
	long blue_total = 0;

	int flag;
	int tmp;

	cin >> n;

	if (n < 3)
	{
		cout << "0" << endl;
		return (0);	
	}
	string str;
	cin >> str;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == 'B')
		{
			arr[i] = 0;
			blue_total += 1;
		}
		else 
		{
			red_total += 1;
			arr[i] = 1;
		}

		if (i == 0)
		{
			flag = arr[i];
			left_color = arr[i];
			left_len += 1;
		}
		else if (i != 0 && flag == arr[i])
			left_len += 1;
		else
			flag = 2;
	}
	
	if ((red_total == 0) || (blue_total == 0))
	{
		cout << "0" << endl;
		return (0);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (i == (n - 1))
		{
			flag = arr[i];
			right_color = arr[i];
			right_len += 1;
		}
		else if (i != (n - 1) && flag == arr[i])
			right_len += 1;
		else
			break;
	}

	if (left_color == 0)
		left_len = blue_total - left_len;
	else
		left_len = red_total - left_len;
	
	if (right_color == 0)
		right_len = blue_total - right_len;
	else
		right_len = red_total - right_len;

	if (right_len > left_len)
	{
		if (left_color == 0)
		{
			if (left_len < red_total)
			{
				cout << left_len << endl;
			}
			else
				cout << red_total << endl;
		}
		else if (left_color == 1)
		{
			if (left_len < blue_total)
			{
				cout << left_len << endl;
			}
			else
				cout << blue_total << endl;
		}
	}
	else if (right_len < left_len)
	{
		if (right_color == 0)
		{
			if (right_len < red_total)
			{
				cout << right_len << endl;
			}
			else
				cout << red_total << endl;
		}
		else if (right_color == 1)
		{
			if (right_len < blue_total)
			{
				cout << right_len << endl;
			}
			else
				cout << blue_total << endl;
		}
	}
	else if (right_len == left_len)
	{
		if (right_color == 0)
		{
			if (right_len < red_total)
			{
				cout << right_len << endl;
			}
			else
				cout << red_total << endl;
		}
		else if (right_color == 1)
		{
			if (right_len < blue_total)
			{
				cout << right_len << endl;
			}
			else
				cout << blue_total << endl;
		}
	}
	
	return (0);
}