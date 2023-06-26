#include <algorithm>
#include <iostream>
using namespace std;

#define ROOT 0
#define LEFT(x) x*2+1
#define RIGHT(x) x*2+2
#define PARENT(x) (int)((x-1)/2)

pair <int, int> *heap;

void heapify(int node, int n) {
    int left = LEFT(node);
    int right = RIGHT(node);
    if (left <= n) {
        if (right <= n && heap[left].second < heap[right].second)
            left = right;
        if (right <= n && heap[left].second == heap[right].second) {
            if (heap[left].first < heap[right].first)
                left = right;
        }
        if (heap[node].second < heap[left].second) {
            swap(heap[node], heap[left]);
            heapify(left, n);
        }
    }
}

void heap_sort(int last_index) {
    for (int i = last_index;i > 0;i--) {
        swap(heap[ROOT], heap[i]);
        heapify(ROOT, i - 1);
    }
}

void seepage(int node) {
    if (node == ROOT)
        return ;
    if (heap[PARENT(node)].second < heap[node].second) {
        swap(heap[PARENT(node)], heap[node]);
        seepage(PARENT(node));
    }
}

int get_result(int n) {
    int remain;

    remain = heap[n - 1].second;
    for (int i = n - 1;i >= 0;i--) {
        remain -= heap[i].first;
        if (i > 0 && remain > heap[i - 1].second)
            remain = heap[i - 1].second;
    }
    if (remain < 0)
        return -1;
    else
        return remain;
}

int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;

    cin >> n;
    heap = new pair <int, int> [n];
    for (int i = 0;i < n;i++) {
        int temp, temp2;
        cin >> temp >> temp2;
        heap[i] = make_pair(temp, temp2);
        seepage(i);
    }
    heap_sort(n - 1);
    cout << get_result(n);
    delete heap;
}