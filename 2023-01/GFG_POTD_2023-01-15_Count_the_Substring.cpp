// GFG POTD 2023/01/15
// Count the Substring
// Hard

#include <bits/stdc++.h>
using namespace std;

// // Unknown Method
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// #define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
// using namespace __gnu_pbds;

// class Solution {
// public:
//     long long countSubstring(string S) {
//         int n = S.size(), cnt = 0;
//         long long ans = 0;
//         ordered_set s;
//         for(int i = 0; i < n; i++) {
//             cnt += S[i] == '1'? 1: -1;
//             ans += s.order_of_key(cnt);
//             ans += cnt > 0;
//             s.insert(cnt);
//         }
//         return ans;
//     }
// };

#define ll long long

class Solution {
public:
    ll countSubstring(string s) {
        ll ans = 0, sum = -1;
        map<ll, ll> help;
        vector<ll> dp(s.size(), 0);
        if(s[0] == '1') {
        	dp[0] = 1;
        	ans = sum = 1;
        }
        help[sum] = 0;
        help[0] = -1;
        for(int i=1; i<s.size(); i++) {
        	ll tmp = 0;
        	if(s[i] == '0') {
        		sum--;
        		if(help.find(sum) != help.end() and help[sum] != -1)
        			tmp += dp[help[sum]];
        	}
        	else {
        		sum++;
        		if(help.find(sum) != help.end()) {
        			if(help[sum] != -1)
        				tmp = dp[help[sum]]+i-help[sum]-1;
        			else
        				tmp = i-help[sum]-1;
        		}
        		else tmp += i+1;
        	}
        	help[sum] = i;
        	dp[i] = tmp;
        	ans += tmp;
        }
        return ans;
    }
};

int main() {
 	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 	int t=1;
 	cin>>t;
 	for(int i=1; i<=t; i++){
	    string S;
	    cin>>S;
	    Solution obj;
	    long long ans = obj.countSubstring(S);
	    cout<<ans<<endl;
 	}
}

/* Sample Input
3
011
0110
0000

Sample Output
4
5
0

*/