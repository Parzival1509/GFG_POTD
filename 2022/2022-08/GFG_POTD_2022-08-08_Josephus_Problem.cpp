//GFG POTD Josephus Problem
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int func(int n, int k){
        //Base Case
        if(n==1) return 0;
        int x=func(n-1, k);
        int y=(x+k)%n;
        return y;
    }
    int josephus(int n, int k){
        return 1+func(n, k);
    }
};

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        Solution ob;
        cout<<ob.josephus(n,k)<<endl;
    }
    return 0;
}