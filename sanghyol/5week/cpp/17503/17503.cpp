// #include <deque>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// deque <pair <int, int> > beer;
// deque <pair <int, int> > answer;

// void	quick_sort(deque <pair <int, int> >::iterator start, deque <pair <int, int> >::iterator end) {
// 	if (start >= end)
// 		return ;
// 	deque <pair <int, int> >::iterator pivot;
// 	pivot = start;
// 	deque <pair <int, int> >::iterator i;
// 	i = start;
// 	i++;
// 	deque <pair <int, int> >::iterator j;
// 	j = end;
// 	while (i <= j) {
// 		while (i <= end && i->second <= pivot->second)
// 			i++;
// 		while (j > start && j->second >= pivot->second)
// 			j--;
// 		if (i > j)
// 			swap(*pivot, *j);
// 		else
// 			swap(*i, *j);
// 	}
// 	quick_sort(start, --j);
// 	++j;
// 	quick_sort(++j, end);
// }

// int main() {
//     ios_base :: sync_with_stdio(false); 
//     cin.tie(NULL); 
//     cout.tie(NULL);

//     int n, m, k;
//     cin >> n >> m >> k;
//     for (int i = 0;i < k;i++) {
//         int v, c;
//         cin >> v >> c;
//         beer.push_back(make_pair(v, c));
//     }
//     quick_sort(beer.begin(), --(beer.end()));
//     deque <pair <int, int> >::iterator iter;
//     for (iter = beer.begin();iter != beer.end();iter++) {
//         if (answer.size() <= n)
//             answer.push_back(*iter);
//         else {
//             pair <int, int> temp = answer.front();
//             answer.pop_back();
//             deque <pair <int, int> >::iterator ans;
//             int sum = 0;
//             for (ans = answer.begin();ans != answer.end();ans++) {
//                 sum += ans->first;
//         }
//     }
// }

// }