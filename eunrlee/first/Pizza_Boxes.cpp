#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    int sum = 0;
    int arr[N][M];
    set <pair<int, int> > v;
    for (int i = 0; i < N; i++) {
        int max = 0;
        int idx;
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
            if (max < arr[i][j]) {
                idx = j;
                max = arr[i][j];
            }
        }
        v.insert(make_pair(i, idx));
    }
    for (int i = 0; i < M; i++) {
        int max = 0;
        int idx;
        for (int j = 0; j < N; j++) {
            if (max < arr[j][i]) {
                idx = j;
                max = arr[j][i];
            }
        }
        v.insert(make_pair(idx, i));
    }
    for (set <pair<int, int> >::iterator iter = v.begin(); iter != v.end(); iter++) {
        sum -= arr[iter->first][iter->second];
    }
    cout << sum;
}