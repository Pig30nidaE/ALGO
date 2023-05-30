#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main () {
    vector <pair <int, int> > v;
    int N;

    cin >> N;
    bool done[N];
    for (int i = 0; i < N; i++) {
        int D, P;
        cin >> P >> D;
        v.push_back(make_pair(P, D));
    }
    sort(v.begin(), v.end());
    long sum = 0;
    int day = 1;
    for (int i = 0; i < N - 1; i++) {
        if (v[i].second > day && !done[i]) {
            sum += v[i].first;
            done[i] = true;
            day++;
        }
    }
    cout << sum;
}