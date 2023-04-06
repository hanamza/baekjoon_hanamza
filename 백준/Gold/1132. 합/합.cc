#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N, t[10];
unsigned long long v[10];
bool isF[10];
string a[50];
pair <unsigned long long, int> b[10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	for ( int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++) {
		string s = a[i];
		unsigned long long k = 1;
		for (int j = s.size() - 1; j >= 0 ; j--) {
			v[s[j] - 'A'] += k;
			k *= 10;
		}
	}

	for (int i = 0; i < N; i++)
		isF[a[i][0] - 'A'] = 1;
	
	for (int i = 0; i < 10; i++)
		b[i] = { v[i],i };
	sort(b, b + 10);

	if (b[0].first != 0 && isF[b[0].second] ) {
		int idx = 1;
		for (;; idx++) if (!isF[b[idx].second]) break;
		auto tmp = b[idx];
		for (int i = idx - 1; i >= 0; i--) b[i + 1] = b[i];
		b[0] = tmp;
	}

	for (int i = 9, j = 9; i >= 0 ; i--, j--) {
		if (b[i].first == 0) break;
		t[b[i].second] = j;
	}
	unsigned long long ans = 0;

	for (int i = 0; i < N; i++) {
		string s = a[i], ret;
		for (int j = 0; j < s.size(); j++)
			ret += t[s[j] - 'A'] + '0';
		ans += stoull(ret);
	}

	cout << ans;

	return 0;
}