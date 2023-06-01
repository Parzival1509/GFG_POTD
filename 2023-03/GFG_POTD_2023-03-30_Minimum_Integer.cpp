// GFG POTD 2023/03/30
// Minimum Integer
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumInteger(int n, vector<int> &a) {
        long long sum = 0;
        int x = INT_MAX;
        for(auto e: a)
            sum += e;
        for(auto e: a) {
            if((long long)e*n >= sum)
                x = min(x, e);
        }
        return x;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &i: a)
            cin>>i;
        Solution ob;
        cout<<ob.minimumInteger(n, a)<<endl;
    }
}

/* Sample Input:
2
3
1 3 2
1
3

Sample Output:
2
3

*/