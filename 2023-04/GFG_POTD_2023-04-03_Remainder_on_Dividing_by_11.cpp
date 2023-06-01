// GFG POTD 2023/04/03
// Remainder on Dividing by 11
// Easy

#include<bits/stdc++.h> 
using namespace std;

#define ll long long

class Solution {
public:
    int xmod11(string x) {
        ll odd = 0, even = 0;
        for(int i=0; i<x.size(); i++)
            if(i%2 == 0) odd += x[i]-'0';
            else even += x[i]-'0';
        ll diff = (odd-even) % 11;
        if(x.size() % 2 == 0) return abs(diff-11) % 11;
        return diff;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}

/* Sample Input:
2
1345
231456786543567898765

Sample Output:
3
1

*/