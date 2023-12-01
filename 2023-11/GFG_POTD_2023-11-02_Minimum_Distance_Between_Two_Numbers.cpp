// GFG POTD 2023/11/02
// Minimum Distance Between Two Numbers
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDist(int a[], int n, int x, int y) {
        int ans = INT_MAX, last = -1;
        
        for(int i = 0; i < n; i++)
            if(a[i] == x || a[i] == y) {
                if(last != -1 && a[last] != a[i]) 
                    ans = min(ans,i - last);
                last = i;
            }
        
        return ans == INT_MAX? -1: ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }

    return 0;
}

/* Sample Input:
2
4 1 2
1 2 3 2
7 42 12
86 39 90 67 84 66 62

Sample Output:
1
-1

*/