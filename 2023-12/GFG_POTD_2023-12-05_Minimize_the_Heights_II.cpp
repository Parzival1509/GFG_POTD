// GFG POTD 2023/12/05
// Minimize the Heights II
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        int dif = arr[n-1] - arr[0];
        int mini, maxi;
        
        for(int i = 0; i < n; i++) {
            mini = min(arr[i] - k, arr[0] + k);
            maxi = max(arr[i - 1] + k, arr[n - 1] - k);
            if(mini < 0) continue;
            
            dif = min(dif, maxi - mini);
        }
        
        return dif;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}

/* Sample Input:
2
2 4
1 5 8 10
3 5
3 9 12 16 20

Sample Output:
5
11

*/