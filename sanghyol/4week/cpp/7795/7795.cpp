#include <algorithm>
#include <iostream>
using namespace std;

int *merged_arr;

void merge(int start, int mid, int end, int *arr) {
    int left_index = start;
    int right_index = mid + 1;
    int merge_index = start;
    while (left_index <= mid && right_index <= end) {
        if (arr[left_index] <= arr[right_index])
            merged_arr[merge_index++] = arr[left_index++];
        else
            merged_arr[merge_index++] = arr[right_index++];
    }
    while (left_index <= mid)
        merged_arr[merge_index++] = arr[left_index++];
    while (right_index <= end)
        merged_arr[merge_index++] = arr[right_index++];
    for (int i = start;i <= end;i++)
        arr[i] = merged_arr[i];
}

void merge_sort(int left, int right, int *arr) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(left, mid, arr);
        merge_sort(mid + 1, right, arr);
        merge(left, mid, right, arr);
    }
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        int n, m;
        cin >> n >> m;

        int *a = new int [n];
        merged_arr = new int [n];
        for (int j = 0;j < n;j++)
            cin >> a[j];
        merge_sort(0, n - 1, a);
        delete merged_arr;

        int *b = new int [m];
        merged_arr = new int [m];
        for (int j = 0;j < m;j++)
            cin >> b[j];
        merge_sort(0, m - 1, b);
        delete merged_arr;

        int sum = 0;
        for (int i = n - 1;i >= 0;i--) {
            int count = 0;
            for (int j = m - 1;j >= 0;j--) {
                if (a[i] > b[j])
                    count++;
            }
            sum += count;
        }
        cout << sum << '\n';

        delete a;
        delete b;
    }
}