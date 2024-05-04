// GFG POTD 2024/04/19
// Find Missing in Second Array
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissing(int a[], int b[], int n, int m) {
        unordered_set<int> st;
        for (int i = 0; i < m; i++)
            st.insert(b[i]);

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (st.count(a[i]) == 0)
                ans.push_back(a[i]);

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        vector<int> ans;
        ans = ob.findMissing(a, b, n, m);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}

/* Sample Input
2
6 5
1 2 3 4 5 10
2 3 1 0 5
5 5
4 3 5 9 11
4 9 3 11 10

Sample Output
4 10 
5 

*/