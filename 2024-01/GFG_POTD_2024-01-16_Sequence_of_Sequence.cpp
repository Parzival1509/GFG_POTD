// GFG POTD 2024/01/16
// Sequence of Sequence
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, vector<int> arr) {
        if(arr.size() == n) return 1;
        if(m == 0) return 0;
        
        int ans = 0;
        for(int j = m; j >= 1; j--) {
            arr.push_back(j);
            int temp = solve(j / 2, n, arr);
            
            if(temp == 0) break;
            
            arr.pop_back();
            ans += temp;
        }
        
        return ans;
    }
    
    int numberSequence(int m, int n) {
        return solve(m, n, {});
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }

    return 0;
}

/* Sample Input:
2
10 4
5 2

Sample Output:
4
6

*/