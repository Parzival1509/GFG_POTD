// GFG POTD 2023/09/22
// First and Last Occurence of x
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> find(int arr[], int n, int x) {
        int lb = -1, rb = -1, lo = 0, hi = n - 1;
        
        // Finding the left bound
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == x) lb = mid;
            
            if(arr[mid] >= x) hi = mid - 1;
            else lo = mid + 1;
        }
        
        // Finding the right bound
        lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            if(arr[mid] == x) rb = mid;
            
            if(arr[mid] > x) hi = mid - 1;
            else lo = mid + 1;
        }
        
        return {lb, rb};
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for(int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        vector<int> ans = ob.find(arr, n, x);
        cout << ans[0] << ' ' << ans[1] << endl;
    }

    return 0;
}

/* Sample Input:
2
9 5
1 3 5 5 5 5 67 123 125
9 7
1 3 5 5 5 5 7 123 125

Sample Output:
2 5
6 6

*/