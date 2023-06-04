#include <iostream>
#include <queue>
using namespace std;

int N, M;
int arr[1001][1001];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[1001][1001] = { 1 };
int maxcnt = 0;
int zerocnt = 0;
queue<pair<int, int> > q;

void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (arr[y][x] == -1) continue;
        for (int i = 0; i < 4; i ++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (arr[ny][nx] == -1) 
                continue;
            else if (nx >= 0 && ny >= 0 && nx < M && ny < N && arr[ny][nx] == 0) {
                cnt[ny][nx] = cnt[y][x] + 1;
                arr[ny][nx] = 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main () {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push(make_pair(i, j));
            } else if (arr[i][j] == 0) {
                zerocnt++;
            }
        }
    }
    if (!zerocnt) {
        cout << 0;
        return (0);
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) {
                cout << -1;
                return 0;
            }
            if (maxcnt < cnt[i][j]) {
                maxcnt = cnt[i][j];
            }
        }
    }
    cout << maxcnt;
}