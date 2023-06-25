#include <deque>
#include <iterator>
#include <iostream>
using namespace std;

deque <pair <int, int> > waterHole;

void	quick_sort(deque <pair <int, int> >::iterator start, deque <pair <int, int> >::iterator end) {
	if (start >= end)
		return ;
	deque <pair <int, int> >::iterator pivot;
	pivot = start;
	deque <pair <int, int> >::iterator i;
	i = start;
	i++;
	deque <pair <int, int> >::iterator j;
	j = end;
	while (i <= j) {
		while (i <= end && i->first <= pivot->first)
			i++;
		while (j > start && j->first >= pivot->first)
			j--;
		if (i > j)
			swap(*pivot, *j);
		else
			swap(*i, *j);
	}
	quick_sort(start, --j);
	++j;
	quick_sort(++j, end);
}

int	padding(int l) {
	deque <pair <int, int> >::iterator iter;
	deque <pair <int, int> >::iterator iter2;
	iter = waterHole.begin();

	int start = 0, end;
	int count = 0;
	for (iter = waterHole.begin();iter != waterHole.end();iter++) {
		end = iter->second;
		if (end > start) {
			if (start < iter->first)
				start = iter->first;
			while (start < end) {
				count++;
				start += l;
			}
		}
	}
	return count;
}

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int n;
	int l;
	cin >> n >> l;
	for (int i = 0;i < n;i++) {
		int start, end;
		cin >> start >> end;
		waterHole.push_back(make_pair(start, end));
	}
	deque <pair <int, int> >::iterator iter1;
	deque <pair <int, int> >::iterator iter2;
	deque <pair <int, int> >::iterator iter3;
	iter1 = waterHole.begin();
	iter2 = waterHole.end();
	iter2--;
	quick_sort(iter1, iter2);
	cout << padding(l);
}