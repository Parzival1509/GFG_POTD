// GFG POTD Minimum Swaps
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwaps(int c[], int v[], int n, int k, int b, int T){
        int ans=0;
        vector<int> vec;
        for(int i=0;i<n;i++)
            vec.push_back(c[i]+v[i]*T);
        int count=0;
        for(int i=n-1;i>=0;i--)
        {
            if(vec[i]>=b){
                if(count>0)
                    ans+=count;
                k--;
            }
            else
                count++;
            if(k==0)
                return ans;
        }
        return -1;
    }
};

int main(){
    int t=1,testcases=1;
    cin>>t;
    while(t>=testcases){
        int n,k,b,T;
        cin>>n>>k>>b>>T;
        int c[n];
        int v[n];
        for(auto &j:c)
            cin>>j;
        for(auto &j:v)
            cin>>j;
        Solution s;
        int ans=s.minimumSwaps(c,v,n,k,b,T);
        cout<<ans<<endl;
        testcases++;
    }
    return 0;
}

/* Sample Input
2
5 3 10 5
0 2 5 6 7
1 1 1 1 4
5 3 10 5
0 2 3 4 7
2 1 1 1 4

Sample Output
0
-1

*/