#include <iostream>
using namespace std;

#define MAX 1000000
typedef long long lld;

lld n, m, k, a, b, c;
lld nums[MAX + 1], tree[4 * MAX + 1];

lld init(lld node, lld start, lld end) {
	if (start == end) return tree[node] = nums[start];
	lld left = node * 2, right = left + 1, mid = (start + end) / 2;

	return tree[node] = init(left, start, mid) + init(right, mid + 1, end);
}

lld query(lld node, lld start, lld end, lld scanStart, lld scanEnd) {
	if (start > scanEnd || end < scanStart) return 0; 
	if (scanStart <= start && end <= scanEnd) return tree[node];
	lld left = node * 2, right = left + 1, mid = (start + end) / 2;
	return query(left, start, mid, scanStart, scanEnd) + query(right, mid + 1, end, scanStart, scanEnd);
}

lld update(lld node, lld start, lld end, lld idx, lld value) {
	if (start > idx || end < idx) return tree[node];
	if (start == end)  return tree[node] = value;
	lld left = node * 2, right = left + 1, mid = (start + end) / 2;
	return tree[node] = update(left, start, mid, idx, value) + update(right, mid + 1, end, idx, value);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (lld i = 0; i < n; i++) cin >> nums[i];
	init(1, 0, n - 1);
	for (lld i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) update(1, 0, n - 1, b - 1, c);
		else {
			cout << query(1, 0, n - 1, b - 1, c - 1) << '\n';
		}
	}
	return 0;
}