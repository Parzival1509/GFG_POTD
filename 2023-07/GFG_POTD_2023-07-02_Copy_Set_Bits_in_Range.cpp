// GFG POTD 2023/07/02
// Copy Set Bits in Range
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int setSetBit(int x, int y, int l, int r) {
        for(int i = l; i <= r; i++) {
            int tmp = 1 << (i - 1);
            if(tmp & y)
                x |= tmp;
        }
        
        return x;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int x, y, l, r;
        cin>>x>>y>>l>>r;
        Solution ob;
        cout<<ob.setSetBit(x, y, l, r)<<"\n";
    }
    return 0;
}

/* Sample Input:
2
44 3 1 5
16 2 1 3

Sample Output:
47
18

*/