// GFG POTD 2024/04/17
// Count Pairs in an Array
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(int arr[], int n) {
        int ct = 0, ans = 0;

        vector<int> b, s;
        for (int i = 0; i < n; i++) {
            b.push_back(i * arr[i]);
            s.push_back(b[i]);
        }

        sort(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            int i1 = lower_bound(s.begin(), s.end(), b[i]) - s.begin();
            ct += i1;
            s.erase(s.begin() + i1);
        }
        
        return ct;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countPairs(a, n) << endl;
    }
}

/* Sample Input
2
4
8 4 2 1
7
5 0 10 2 4 1 6

Sample Output
2
5

*/