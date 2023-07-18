#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
	int n;
	cin >> n;
	map <int, int> depth_info;
	int size = 0;
	int index = 0;
	for (int depth = 0;depth < n + 1;depth++) {
		size += depth;
		for (int j = 0;j < depth + 1;j++) {
			depth_info[index] = depth;
			index++;
		}
	}
	int	*triangle;
	triangle = new int[size];
	index = 0;
	int index2 = 0;
	for (int depth = 0;depth < n;depth++) {
		for (int i = 0;i < depth + 1;i++) {
			cin >> triangle[index];
			index++;
		}
		for (int i = 0;i < depth + 1;i++) {
			int lnode = index2 - (depth - 1) - 2;
			int	rnode = index2 - (depth - 1) - 1;
			int lnode_res = -1;
			int	rnode_res = -1;
			if (0 <= lnode && lnode < size && depth_info[lnode] == depth - 1)
				lnode_res = triangle[lnode] + triangle[index2];
			if (0 <= rnode && rnode < size && depth_info[rnode] == depth - 1)
				rnode_res = triangle[rnode] + triangle[index2];
			if (lnode_res >= 0 && rnode_res < 0)
				triangle[index2] = lnode_res;
			if (lnode_res < 0 && rnode_res >= 0)
				triangle[index2] = rnode_res;
			if (lnode_res >= 0 && rnode_res >= 0) {
				if (lnode_res > rnode_res)
					triangle[index2] = lnode_res;
				else
					triangle[index2] = rnode_res;
			}
			index2++;
		}
	}
	index = size - 1;
	int	depth_max = depth_info[index];
	int max = 0;
	while (index >= 0 && depth_info[index] == depth_max) {
		if (triangle[index] > max)
			max = triangle[index];
		index--;
	}
	cout << max;
}