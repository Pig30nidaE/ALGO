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
    int target;
    if (left < n && right >= n)
        target = left;
    else if (right < n && left >= n)
        target = right;
    else if (left > n && right > n)
        return ;
    else {
        if (heap[left].second > heap[right].second)
            target = left;
        else
            target = right;
    }
    if (heap[target].second > heap[node].second) {
        swap(heap[target], heap[node]);
        heapify(target, n);
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

void heap_sort(int last_index, int n) {
    for (int i = last_index;i > 0;i--) {
        swap(heap[ROOT], heap[last_index]);
        heapify(ROOT, last_index - 1);
        // seepage(last_index);
    }
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
    heap_sort(n - 1, n);
    for (int i = 0;i < n;i++)
        cout << heap[i].second << endl;
}