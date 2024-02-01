// GFG POTD 2023/09/27
// Find the Closest Pair from Two Arrays
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> ans(2);
        
        int mn = INT_MAX, i = 0, j = m - 1;
        while(i < n && j >= 0) {
            int sum = arr[i] + brr[j];
            int diff = abs(sum - x);
            if(diff < mn) {
                mn = diff;
                ans[0] = arr[i];
                ans[1] = brr[j];
            }
            if(sum > x) j--;
            else i++;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n, x;
        cin >> n >> m >> x;
        int a[n], b[m];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << ans[0] + ans[1] << endl;
    }
    
    return 0;
}

/* Sample Input:
2
4 4 32
1 4 5 7
10 20 30 40
4 4 50
1 4 5 7
10 20 30 40

Sample Output:
31
47

*/