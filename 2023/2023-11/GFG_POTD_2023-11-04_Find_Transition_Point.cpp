// GFG POTD 2023/11/04
// Find Transition Point
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int transitionPoint(int arr[], int n) {
        int lo = 0, hi = n - 1, ans = -1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == 1) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    
    return 0;
}

/* Sample Input:
3
5
0 0 0 1 1
4
0 0 0 0
4
1 1 1 1

Sample Output:
3
-1
0

*/