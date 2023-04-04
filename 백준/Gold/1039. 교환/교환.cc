#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int nextMaximum[1000001][11];

void solve(void);

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}

int dfs(std::string num, int depth)
{
	if (0 == depth)
		return stoi(num);

	const int currNum = stoi(num);
	int& maximum = nextMaximum[currNum][depth];

	if (0 <= maximum)
		return maximum;

	for (int i = 0; i < num.length(); i++)
	{
		for (int j = i + 1; j < num.length(); j++)
		{
			if (0 == i && '0' == num[j])
				continue;

			swap(num[i], num[j]);
			maximum = std::max(maximum, dfs(num, depth - 1));
			swap(num[i], num[j]);
		}
	}

	return maximum;
}

void solve(void)
{
	string n;
	int k;
	cin >> n >> k;

	memset(nextMaximum, -1, sizeof(int) * 1000001 * 11);

	cout << dfs(n, k);
}