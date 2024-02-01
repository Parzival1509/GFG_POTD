// GFG POTD 2023/08/20
// Number of Occurences
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int count(int arr[], int n, int x) {
        int start = -1, end = -1;
        int lo = 0, hi = n - 1;
        
        // Finding the lower bound
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == x) {
                start = mid;
                hi = mid - 1;
            }
            else if(arr[mid] > x)
                hi = mid - 1;
            else lo = mid + 1;
        }
        
        lo = 0, hi = n - 1;
        // Finding the upper bound
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == x) {
                end = mid;
                lo = mid + 1;
            }
            else if(arr[mid] > x)
                hi = mid - 1;
            else lo = mid + 1;
        }
        
        return (start == -1)? 0: end - start + 1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << endl;
    }
    return 0;
}

/* Sample Input:
2
7 2
1 1 2 2 2 2 3
7 4
1 1 2 2 2 2 3

Sample Output:
4
0

*/