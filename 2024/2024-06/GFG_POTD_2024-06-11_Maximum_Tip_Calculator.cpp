// GFG POTD 2024/06/11
// Maximum Tip Calculator
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxTip(int n, int x, int y, vector<int>& arr, vector<int>& brr) {
        vector<pair<int, int>> temp;

        for (int i = 0; i < n; i++)
            temp.push_back({abs(arr[i] - brr[i]), i});

        sort(temp.begin(), temp.end());
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            int index = temp[i].second;
            if (arr[index] > brr[index]) {
                if (x > 0) {
                    ans += arr[index];
                    x--;
                } else {
                    ans += brr[index];
                    y--;
                }
            } else {
                if (y > 0) {
                    ans += brr[index];
                    y--;
                } else {
                    ans += arr[index];
                    x--;
                }
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        vector<int> brr(n, 0);
        for(int &i: brr)
            cin >> i;
        cout << ob.maxTip(n, x, y, arr, brr) << endl;
    }
    return 0;
}

/* Sample Input
3
5 3 3
1 2 3 4 5
5 4 3 2 1
8 4 4
1 4 3 2 7 5 9 6
1 2 3 6 5 4 9 8
7 3 4
8 7 15 19 16 16 18
1 7 15 11 12 31 9

Sample Output
21
43
110

*/