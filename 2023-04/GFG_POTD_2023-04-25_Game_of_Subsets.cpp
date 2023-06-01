// GFG POTD 2023/04/25
// Game Of Subsets
// Hard

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> temp;

    ll helper(int i, vector<int>& options, ll prod, vector<int>& freq) {
        int n = options.size();
        if(i == n) return 1;
    
        ll option = options[i], pick = 0;
        ll g = __gcd(prod, option);
        
        if(g == 1 && freq[option]) {
            temp.push_back(option);
            pick = freq[option] * helper(i+1, options, prod * options[i], freq);
            pick %= MOD;
            temp.pop_back();
        }
        ll notPick = helper(i+1, options, prod, freq);
        
        return (pick + notPick) % MOD;
    }

    int goodSubsets(vector<int> &arr, int n) {
        vector<int> freq(31);
        for(auto it: arr) freq[it]++;
        
        vector<int> options;
        for(int i = 1; i <= 30; i++) {
            int num = i;
            bool ok = true;
            for(int j = 2; j*j <= i; j++) {
                if(num % (j*j) == 0) {
                    ok = false;
                    break;
                }
            }
            if(ok) options.push_back(num);
        }
        
        return helper(0, options, 1, freq) - 1 - freq[1];
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.goodSubsets(a, n)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
1 2 3 4
3
2 2 3

Sample Output:
6
5

*/