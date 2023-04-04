#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[2000];

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int num, result = 0, val;
    cin >> num;
    for (int i = 0; i < num; i++)
        cin >> arr[i];
    sort(arr, arr + num);
    for (int i = 0; i < num; i++) {
        val = arr[i];
        int l = 0, r = num - 1, sum;
        while (l < r) {
            sum = arr[l] + arr[r];
            if (sum == val) {
                if (l != i && r != i) {
                    result++;
                    break;
                }
                else if (l == i) l++;
                else if (r == i) r--;
            }
            else if (sum < val) l++;
            else r--;
        }
    }
    cout << result << "\n";
	
    return 0;
}