#include <iostream>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
#define MAX 50 + 1
// 전역 
vector<vector<int>> child_vec;
int answer = 0, del_node;

// 자식 노드를 dfs를 이용하여 센다.
// 자식 노드가 1개 있으면, 해당 노드가 삭제할 노드인지 확인한다.
void leaf(int now_node) {
    if (del_node == now_node) return;
    int ch_size = child_vec[now_node].size();
    switch (ch_size) {
    case 0:
        answer++; return;
        break;
    case 1:
        if (child_vec[now_node][0] == del_node) {
            answer++; break;
        }
    default:
        for (int i = 0; i < ch_size; i++)
           leaf(child_vec[now_node][i]);
        break;
    }
}

int main() {
    // input 받아서 루트, 부모, 자식 처리하기 
    int N, root; 
    scanf("%d", &N);
    child_vec.resize(N);

    for (int i = 0; i < N; i++) {
        int parent; 
        scanf("%d", &parent);
        if (parent != -1) child_vec[parent].push_back(i);
        else root = i;
    }

    scanf("%d", &del_node);
    leaf(root);
    printf("%d", answer);
    return 0;
}
