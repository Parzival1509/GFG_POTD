// GFG POTD 2023/07/03
// Maximum Index
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIndexDiff(int arr[], int n) {
        int maxi = -1;
        int *left = new int[n], *right = new int[n];
        
        left[0] = arr[0];
        for(int i = 1; i < n; i++ )
            left[i] = min(arr[i], left[i - 1]);
        
        right[n-1] = arr[n-1];
        for(int i = n-2; i >=0; i--)
            right[i] =  max(arr[i], right[i + 1]);
        
        int i = 0, j = 0;
        while(j < n && i < n) {
            if(left[i] <= right[j]) {
                maxi = max(maxi, j - i);
                j++;
            }
            else i++;
        }
        
        return maxi;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for(i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input:
2
2
18 17
9
34 8 10 3 2 80 30 33 1

Sample Output:
0
6

*/