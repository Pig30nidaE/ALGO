#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int ft_binary_search(int target, int left, int right, vector <int > nrr)
{
	int mid = (left + right) / 2;
	if (left > right) // 이거 필수
		return (-1);
	if (nrr[mid] == target)
		return mid;
	else if (nrr[mid] < target)
		return (ft_binary_search(target, mid + 1, right, nrr));
	else if (nrr[mid] > target)
		return (ft_binary_search(target, left, mid - 1, nrr));
	return (0);
}

int ft_binary_search(int target, vector<int>::iterator left, vector<int>::iterator right, vector<int>& nrr) {
    int mid = distance(left, right) / 2;
    vector<int>::iterator midIter = left + mid;
    
	if (left > right) //이거 필수
		return (-1);
    if (*midIter == target)
        return (distance(nrr.begin(), midIter));
    else if (*midIter < target)
        return (ft_binary_search(target, midIter + 1, right, nrr));
    else if (*midIter > target)
        return (ft_binary_search(target, left, midIter, nrr));
    return (-1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, value, len;
	cin >> n;
	vector <int > nrr;
	int *mrr = new int[n]();
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		nrr.push_back(value);
		mrr[i] = value;
	}
	sort(nrr.begin(), nrr.end());
	nrr.erase(unique(nrr.begin(), nrr.end()), nrr.end());
	// len = nrr.size(); -> 이걸로 시간초과 떠서 interater 직접 쓰는걸로 바꿈 good
	for (int i = 0; i < n; i++)
	{
		printf("%d ", ft_binary_search(mrr[i], nrr.begin(), nrr.end(), nrr));
	}
	
}