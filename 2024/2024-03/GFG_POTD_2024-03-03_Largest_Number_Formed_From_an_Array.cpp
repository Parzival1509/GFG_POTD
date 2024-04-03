// GFG POTD 2024/03/03
// Largest Number Formed From an Array
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const string a, const string b) {
        return a + b > b + a;
    }

    string printLargest(int n, vector<string>& arr) {
        string ans = "";
        sort(arr.begin(), arr.end(), cmp);
        for (auto it : arr)
            ans += it;

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.printLargest(n, arr);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
5
3 30 34 5 9
4
54 546 548 60

Sample Output
9534330
6054854654

*/