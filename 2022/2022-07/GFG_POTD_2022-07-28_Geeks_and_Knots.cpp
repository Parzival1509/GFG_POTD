#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution{
private:
int dp[1001][1001];
long long int md=1e9+7;
long long int combination(int n,int k)
{
    if(k>n) return 0;
    if(k==0 || k==n) return 1;
    
    if(dp[n][k]!=-1) return dp[n][k];
    
    return dp[n][k] = (combination(n-1,k)%md + combination(n-1,k-1)%md)%md;
}    
public:
    int knots(int M, int N, int K){
        // code here
       memset(dp,-1,sizeof(dp));
       long long int a=combination(M,K)%md;
       long long int b=combination(N,K)%md;
       
       return (a*b)%md;
    }
};

int main(){
	Solution ob;
    int m, n, k;
    cin>>m>>n>>k;
    cout<<ob.knots(m, n, k);
    return 0;
}