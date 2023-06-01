//GFG POTD Count Palindromic Subsequences
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int  countPS(string str)
    {
        int n=str.length(), m=1e9+7;
        vector<long long int> c(n,0), p(n,0);
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j)
                	c[j] = 1;
                else if(str[i]==str[j])
                	c[j] = (c[j-1]+p[j]+1)%m;
                else
                	c[j] = (c[j-1]+p[j]-p[j-1]+m)%m;
            }
            p=c;
        }
        return p[n-1];
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}

/* Sample Input

Sample Output

*/