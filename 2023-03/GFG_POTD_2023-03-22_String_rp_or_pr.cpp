// GFG POTD 2023/03/22
// String rp or pr
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {   
private:
    ll remove(string &str, string p, int x) {
        ll i = 0 , ans = 0;
        for(int j = 0; j<str.size(); j++) {
            str[i++] = str[j];
            if(i >= 2 and str[i-2] == p[0] and str[i-1] == p[1]) {
                i -= 2;
                ans += x;
            }
        }
        str.resize(i);
        return ans;
    }

public:
    ll solve(int X, int Y, string S) {
        string a = "pr", b = "rp";
        if(X < Y) {
            swap(a, b);
            swap(X, Y);
        }
        return remove(S, a, X) + remove(S, b, Y);
    }
};

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int X, Y;
        cin>>X>>Y;
        string S;
        cin>>S;
        Solution obj;
        ll answer = obj.solve(X, Y, S);
        cout<<answer<<endl;
    }
}

/* Sample Input:
2
5 4
abppprrr
7 7
prpptppr

Sample Output:
15
14

*/