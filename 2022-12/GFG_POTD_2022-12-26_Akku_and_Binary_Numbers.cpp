// GFG POTD 2022/12/26
// Akku and Binary Numbers
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void precompute() {
        
    }
    
    long long solve(long long l, long long r){
        long long ans=0;
        for(int i=0; i<63; i++)
            for(int j=i+1; j<63; j++)
                for(int k=j+1; k<63; k++){
                    long long curr = 0;
                    curr |= (1l<<i);
                    curr |= (1l<<j);
                    curr |= (1l<<k);
                    if(curr>=l and curr<=r) ans++;
                }
        return ans;
    }
};

int main() {
    int t;
    Solution ob;
    // ob.precompute();
    cin>>t;
    while(t--) {
        long long l, r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}

/* Sample Input
2
11 19
25 29

Sample Output
4
3

*/