#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

	for (int i = 0; i < r; i++)
	{
		cout << str[i] << "\n";
	}



}