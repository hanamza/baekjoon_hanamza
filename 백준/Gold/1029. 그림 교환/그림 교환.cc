#include<iostream>
#include<string.h>
#include<string>
using namespace std;

const int MAX_ARTISTS = 15;
const int MAX_PRICE = 9;

int artist_num;
int price_board[MAX_ARTISTS][MAX_ARTISTS];
int dp[1 << MAX_ARTISTS][MAX_ARTISTS][MAX_PRICE + 1];

int Resell(int visited, int artist, int price) {
    int& ret = dp[visited][artist][price];
    if (ret != -1) {
        return ret;
    }
    ret = 0;
    for (int i = artist_num - 1; i >= 1; --i) {
        if (!(visited & (1 << i)) && price_board[artist][i] >= price) {
            int next_visited = visited | (1 << i);
            ret = max(ret, Resell(next_visited, i, price_board[artist][i]) + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> artist_num;

    for (int i = 0; i < artist_num; ++i) {
        string temp;
        cin >> temp; 
        for (int j = 0; j < artist_num; j++) {
            price_board[i][j] = temp[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));
    Resell(1, 0, 0);
    cout << dp[1][0][0] + 1 << "\n";

    return 0;
}
