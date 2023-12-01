// GFG POTD 2023/11/26
// Print Pattern
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    
    void dec(vector<int> &ans) {
        if(n <= 0) return;
        
        n -= 5;
        ans.push_back(n);
        dec(ans);
    }
    
    void inc(int N, vector<int> &ans) {
        if(n == N) return;
        
        n += 5;
        ans.push_back(n);
        inc(N, ans);
    }

    vector<int> pattern(int N) {
        vector<int> ans;
        n = N;
        ans.push_back(n);
        dec(ans);
        inc(N, ans);
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout << u << " ";
        cout << "\n";
    }

    return 0;
}

/* Sample Input:
2
10
16

Sample Output:
10 5 0 5 10 
16 11 6 1 -4 1 6 11 16 

*/