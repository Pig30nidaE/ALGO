#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define BLUE 1
#define RED 2 

int get_cost(string ball_box, int last_flag, int n, char target_color, int blue_count, int red_count) {
    int index = n - 1;
    int reduce_count = 0;
    int check_color;
    int count;

    if (target_color == 'B') {
        check_color = BLUE;
        count = blue_count;
    }
    else {
        check_color = RED;
        count = red_count;
    }
    if (last_flag == check_color) {
        while (ball_box[index] && ball_box[index] == target_color) {
            index--;
            reduce_count++;
        }
        return count - reduce_count;
    }
    else {
        return count;
    }
}

int get_last_color_flag(string ball_box, int n) {
    if (ball_box[n - 1] == 'B')
        return BLUE;
    return RED;
}

int main() {
    string ball_box;
    int n;
    int last_flag;
    int blue_count = 0;
    int red_count = 0;

    cin >> n;
    cin.ignore();
    getline(cin, ball_box);
    for (int i = 0;i < n;i++) {
        if (ball_box[i] == 'B')
            blue_count++;
        else
            red_count++;
    }
    if (!blue_count || !red_count) {
        printf("%d", 0);
        return 0;
    }
    int *cost = new int[4];
    last_flag = get_last_color_flag(ball_box, n);
    cost[0] = get_cost(ball_box, last_flag, n, 'B', blue_count, red_count);
    cost[1] = get_cost(ball_box, last_flag, n, 'R', blue_count, red_count);
    reverse(ball_box.begin(), ball_box.end());
    last_flag = get_last_color_flag(ball_box, n);
    cost[2] = get_cost(ball_box, last_flag, n, 'B', blue_count, red_count);
    cost[3] = get_cost(ball_box, last_flag, n, 'R', blue_count, red_count);
    int smallest;
    for (int i = 0;i < 4;i++)
        smallest = smallest < cost[i]? smallest : cost[i];
    printf("%d", smallest);
    delete cost;
    return 0;
}