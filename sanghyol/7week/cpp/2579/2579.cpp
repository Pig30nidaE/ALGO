#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int	*stairs;

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int n;
	cin >> n;
	stairs = new int [n];

	for (int i = 0;i < n;i++)
		cin >> stairs[i];
	vector <pair <int, int> > dp;
	int	index = 0;
	int	vector_index = 0;
	dp.push_back(make_pair(stairs[0],0));
	while (vector_index != dp.size()) {
		int seq = dp.at(vector_index).second;
		if (index + 1 < n) {
			if (seq < 2)
				dp.push_back(make_pair(stairs[index + 1], seq + 1));
			else
				dp.push_back(make_pair(0, 0));
		}
		if (index + 2 < n)
			dp.push_back(make_pair(stairs[index + 2], 0));
		vector_index++;
	}
	vector <pair <int, int> >::iterator test;
	for (test = dp.begin();test != dp.end();test++)
		cout << test->first << ' ' << test->second << endl;
}