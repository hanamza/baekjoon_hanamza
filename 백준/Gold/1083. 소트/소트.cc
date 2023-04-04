#include<iostream>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N, S;
	cin >> N;
	vector<int> v(N, 0);
	for (int i = 0; i < N; ++i) cin >> v[i];
	cin >> S;
	for (int i = 0; i < N; i++)
	{
		int max = v[i];
		int maxi = i;
		for (int j = i + 1; j < N; j++)
		{
			if (S - (j - i) >= 0)
			{
				if (max < v[j])
				{
					max = v[j];
					maxi = j;
				}
			}
		}
		for (int j = maxi; j > i; j--)
			swap(v[j], v[j - 1]);
		S -= (maxi - i);
		if (S <= 0)
			break;
	}
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	return 0;
}