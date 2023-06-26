#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

const std::string WHITESPACE = " \n\r\t\f\v";

void	quick_sort(vector <string>::iterator start, vector <string>::iterator end) {
	if (start >= end)
		return ;
	vector <string>::iterator pivot;
	pivot = start;
	vector <string>::iterator i;
	i = start;
	i++;
	vector <string>::iterator j;
	j = end;
	while (i <= j) {
		while (i <= end && *i <= *pivot)
			i++;
		while (j > start && *j >= *pivot)
			j--;
		if (i > j)
			swap(*pivot, *j);
		else
			swap(*i, *j);
	}
	quick_sort(start, --j);
	++j;
	quick_sort(++j, end);
}

string ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

string rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

string trim(const std::string &s) {
    return rtrim(ltrim(s));
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;

    while (getline(ss, temp, delimiter)) {
        if (trim(temp).length() >= 1)
            answer.push_back(trim(temp));
    }
    return answer;
}


int main() {
	ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int r, c;

    cin >> r >> c;
    cin.ignore();
    string crossword[r];
    for (int i = 0;i < r;i++)
        getline(cin, crossword[i]);
    string rot_crossword[c];
    for (int i = 0;i < c;i++) {
        for (int j = 0;j < r;j++)
            rot_crossword[i].push_back(crossword[j][i]);
    }
    vector <string> word_set;
    vector <string> temp;
    for (int i = 0;i < r;i++) {
        temp = split(crossword[i], '#');
        word_set.insert(word_set.end(), temp.begin(), temp.end());
    }
    for (int i = 0;i < c;i++) {
        temp = split(rot_crossword[i], '#');
        word_set.insert(word_set.end(), temp.begin(), temp.end());
    }
    vector <string>::iterator iter;
    vector <string>::iterator iter2;
    iter = word_set.begin();
    iter2 = word_set.end();
    iter2--;
    quick_sort(iter, iter2);
    for (int i = 0;i < word_set.size();i++) {
        if (word_set[i].length() > 1) {
            cout << word_set[i];
            return 0;
        }
    }
}