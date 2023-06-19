#include <iterator>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;


int compare(string target1, string target2) {
    if (target1.length() < target2.length())
        return 1;
    if (target1.length() > target2.length())
        return -1;
    string::iterator iter1;
    string::iterator iter2;
    iter1 = target1.begin();
    iter2 = target2.begin();
    long long iter1_sum = 0;
    long long iter2_sum = 0;
    for (iter1 = target1.begin();iter1 != target1.end();iter1++) {
        if (isdigit(*iter1))
            iter1_sum += *iter1 - 48;
    }
    for (iter2 = target2.begin();iter2 != target2.end();iter2++) {
        if (isdigit(*iter2))
            iter2_sum += *iter2 - 48;
    }
    if (iter1_sum < iter2_sum)
        return 1;
    if (iter1_sum > iter2_sum)
        return -1;
    if (target1 < target2)
        return 1;
    if (target1 > target2)
        return -1;
    return 0;
}

string *selection_sort(string *guitar, int n) {
    int index;
    for (int i = 0;i < n;i++) {
        index = i;
        for (int j = i + 1;j < n;j++) {
            if (compare(guitar[index], guitar[j]) <= 0)
                index = j;
        }
        if (index != i)
            swap(guitar[i], guitar[index]);
    }
    return guitar;
}

int main() {
    int n;
    int max = 0;

    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n;
    if (!n) {
        cout << 0;
        return 0;
    }
    string guitar[n];
    for (int i = 0;i < n;i++) {
        cin >> guitar[i];
    }
    string *answer = selection_sort(guitar, n);
    for (int i = 0;i < n;i++)
        cout << guitar[i] << '\n';
}