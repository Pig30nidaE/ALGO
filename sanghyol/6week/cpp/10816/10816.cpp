#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;

int	binary_search(int start, int end, int *card, int to_find, map <int, int> &card_count) {
	int mid = (start + end) / 2;
	if (mid == start) {
		if (card[mid] == to_find)
			return 1;
		return 0;
	}
	if (card[mid] < to_find)
		return binary_search(mid + 1, end, card, to_find, card_count);
	else if (card[mid] > to_find)
		return binary_search(start, mid, card, to_find, card_count);
	else 
		return card_count.find(card[mid])->second;
}

int main() {
	int n;
	scanf("%d", &n);
	int card[n];
	map <int, int> card_count;
	map <int, int>::iterator iter;
	for (int i = 0;i < n;i++) {
		scanf("%d", &card[i]);
		iter = card_count.find(card[i]);
		if (iter != card_count.end())
            (iter->second)++;
		else
			card_count[card[i]] = 1;
	}
	sort(card, card + n);
	int m;
	scanf("%d", &m);
	int to_find[m];
	for (int i = 0;i < m;i++)
		scanf("%d", &to_find[i]);
	for (int i = 0;i < m;i++)
		printf("%d ", binary_search(0, n, card, to_find[i], card_count));
}