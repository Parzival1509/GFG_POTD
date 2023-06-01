// GFG POTD 2023/04/23
// Minimum Number
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int minimumNumber(int n, vector<int> &a) {
        if(n <= 1) return 0;
        int ans = a[0];
        for(int i = 1; i < n; i++)
            ans = __gcd(min(ans, a[i]), max(ans, a[i]));
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    Solution ob;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n, 0);
        for(int &i: a)
            cin>>i;
        cout<<ob.minimumNumber(n, a)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
3 2 4
5
2 4 6 5 4

Sample Output:
1
1

*/