// GFG POTD 2024/04/10
// Party of Couples
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSingle(int n, int arr[]) {
        int ans = 0;
        for(int i = 0; i < n; i++)
            ans ^= arr[i];
            
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.findSingle(n, arr) << endl;
    }
    return 0;
}

/* Sample Input
2
5
1 2 3 2 1
11
1 2 3 5 3 2 1 4 5 6 6

Sample Output
3
4

*/