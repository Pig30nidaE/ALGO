#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    long sum = 0;
    long arr[N][M];
    set <pair<long, long> > v;
    for (long i = 0; i < N; i++) {
        long max = 0;
        long idx;
        for (long j = 0; j < M; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
            if (max < arr[i][j]) {
                idx = j;
                max = arr[i][j];
            }
        }
        v.insert(make_pair(i, idx));
    }
    for (long i = 0; i < M; i++) {
        long max = 0;
        long idx;
        for (long j = 0; j < N; j++) {
            if (max < arr[j][i]) {
                idx = j;
                max = arr[j][i];
            }
        }
        v.insert(make_pair(idx, i));
    }
    for (set <pair<long, long> >::iterator iter = v.begin(); iter != v.end(); iter++) {
        sum -= arr[iter->first][iter->second];
    }
    cout << sum;
}