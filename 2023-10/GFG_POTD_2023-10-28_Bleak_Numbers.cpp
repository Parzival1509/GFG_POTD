// GFG POTD 2023/10/28
// Bleak Numbers
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int is_bleak(int n) {
       // // Approach 1: T.C. = O(N)
       // for(int i = n - sqrt(n); i < n; i++)
       //     if((i + __builtin_popcount(i)) == n)
       //         return 0;
       // return 1;
       
       // Approach 2: T.C. = O(1)
       for(int cnt = 0; cnt <= 31; cnt++) {
            int target = n - cnt;
            if(target < 0) break;
            
            int noSetBit = __builtin_popcount(target); 
            if(noSetBit == cnt)
                return 0;
        }
        
        return 1;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n; 
        cin >> n;
        Solution ob;
        int ans = ob.is_bleak(n);
        cout << ans << "\n";
    }

    return 0;
}

/* Sample Input:
2
3
4

Sample Output:
0
1

*/