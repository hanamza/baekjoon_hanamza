#include <iostream>
using namespace std;

int find_p(int parent[], int x) {
    if (x != parent[x])
        return parent[x] = find_p(parent, parent[x]);
    else
        return parent[x];
}

void mer(int parent[], int x, int y) {
    int px = find_p(parent, parent[x]);
    int py = find_p(parent, parent[y]);
    if (px != py) {
        if (px < py)
            parent[py] = parent[px];
        else
            parent[px] = parent[py];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int know_tru;
    cin >> know_tru;

    int parent[53];

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    int temp;
    for (int i = 0; i < know_tru; i++) {
        cin >> temp;
        parent[temp] = 0;
    }

    int Pnum;
    int temp2;

    int arr[53][53];
    int arrsiz[53];
    for (int i = 0; i < m; i++) {
        cin >> Pnum;
        cin >> temp;
        arrsiz[i] = Pnum;
        arr[i][0] = temp;

        for (int j = 1; j < Pnum; j++) {
            cin >> temp2;
            arr[i][j] = temp2;
            mer(parent, temp, temp2);
        }
    }
    int answer = m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < arrsiz[i]; j++) {
            if (find_p(parent, parent[arr[i][j]]) == 0) {
                answer--;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}