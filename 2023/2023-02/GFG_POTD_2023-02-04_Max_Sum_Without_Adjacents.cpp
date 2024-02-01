// GFG POTD 2023/02/04
// Max Sum Without Adjacents
// Easy

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int findMaxSum(int *arr, int n) {
        ll a = 0, b = 0;
        for(int i=1; i<=n; i++) {
            ll tmp = a;
            a = max(a, b);
            b = tmp+arr[i-1];
        }
        return max(a, b);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input:
3
6
5 5 10 100 10 5
4
3 2 7 10
1
1100

Sample Output:
110
13
1100

*/