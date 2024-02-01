// GFG POTD Power of 2 and Subsequences
#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    long long numberOfSubsequences(int N, long long A[]){
        long long n = 0;
        int m = 1e9+7, res=1;
        for(long long i = 0; i<N; i++)
            if((A[i]&(A[i]-1)) == 0)
                n++;
        while(n--)
            res = (res*2)%m;
        return res-1;
    }
};

int main(){ 
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
}

/*
Sample Input:
2
3
1 2 6
3
3 5 7

Sample Output:
3
0

/*