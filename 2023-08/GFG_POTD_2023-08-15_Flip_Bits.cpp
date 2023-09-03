// GFG POTD 2023/08/15
// Flip Bits
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOnes(int a[], int n) {
        int ans = 0, sum = 0;

        for(int i = 0; i < n; i++) {
            if(a[i] == 0) sum++;
            else sum--;

            ans = max(ans, sum);
            if(sum < 0) sum = 0;
        }

        for(int i = 0; i < n; i++)
            ans += a[i];
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n + 5];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maxOnes(a, n) << endl;
    }
    return 0;
}

/* Sample Input:
2
5
1 0 0 1 0
7
1 0 0 1 0 0 1

Sample Output:
4
6

*/