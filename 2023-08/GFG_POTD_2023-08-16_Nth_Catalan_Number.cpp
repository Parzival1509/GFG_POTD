// GFG POTD 2023/08/16
// Nth Catalan Number
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCatalan(int n) {
        const int MOD = 1e9 + 7;
        vector<int> catalan(n + 1, 0);
        catalan[0] = 1;
        
        for(int i =1; i<= n; i++)
            for(int j=0; j< i; j++)
                catalan[i] = (catalan[i] + (catalan[j] * 1LL * catalan[i - j - 1]) % MOD) % MOD;
        
        return catalan[n];
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        Solution obj;
        cout<< obj.findCatalan(n) <<"\n";    
    }
    return 0;
}

/* Sample Input:
2
4 5

Sample Output:
14
42

*/