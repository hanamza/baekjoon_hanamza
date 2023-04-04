#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 987654321;
char coin[21][21];

int count(int c) {
    int ret = 0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            char now = coin[i][j];
            if ((c & (1 << j)) != 0) {
                now = (now == 'H') ? 'T' : 'H';
            }
            if (now == 'H') cnt++;
        }
        ret += min(cnt, N - cnt);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> coin[i][j];
        }
    }

    for (int i = 0; i < (1 << N); i++) {
        ans = min(ans, count(i));
    }

    cout << ans << '\n';

    return 0;
}
