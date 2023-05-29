#include <iostream>
#include <string>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N;
    string ball;
    int acnt = 0, bcnt = 0, ccnt = 0, dcnt = 0;

    cin >> N;
    cin >> ball;
    
    for (int i = N - 1; i >= 0; i--) {
        int pos = 0;
        if (ball[i] == 'R'){
            if (i >= 1 && (ball.substr(0, i)).find("B", pos) != string::npos) {
                bcnt++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        size_t pos = i + 1;
        if (ball[i] == 'R' && ball.find("B", pos) != string::npos) {
            acnt++;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        int pos = 0;
        if (ball[i] == 'B'){
            if (i >= 1 && (ball.substr(0, i)).find("R", pos) != string::npos) {
                dcnt++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        size_t pos = i + 1;
        if (ball[i] == 'B' && ball.find("R", pos) != string::npos) {
            ccnt++;
        }
    }
    cout << min(min(acnt, bcnt), min (ccnt, dcnt));
}