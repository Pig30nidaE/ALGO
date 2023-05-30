#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(pair<int, int > a, pair<int, int > b) {
    return a.first < b.first;
}

int main () {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    long N;
    vector<pair<long, long > > v;
    vector<long> H(N), A(N);
    cin >> N;
    long sum = 0;
    for (long i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (long i = 0; i < N; i++) {
        cin >> A[i];
        v.push_back(make_pair(A[i], H[i]));
    }
    sort(v.begin(), v.end(), cmp);

    for (long i = 0; i < N; i++) {
        sum += v[i].second + v[i].first * i;
    }
    cout << sum;
}