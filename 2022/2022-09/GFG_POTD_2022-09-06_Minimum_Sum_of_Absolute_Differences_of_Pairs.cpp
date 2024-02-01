// GFG POTD 2022/09/06
// Minimum Sum of Absolute Differences of Pairs
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        long long sum = 0;
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int i=0; i<N; i++)
            sum += abs(A[i]-B[i]);
        return sum;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> A(N),B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
            cin>>B[i];
        }
        Solution ob;
        cout<<ob.findMinSum(A,B,N)<<endl;
    }
}

/* Sample Input
2
4
4 1 8 7
2 3 6 5
3
4 1 2
2 4 1

Sample Output
6
0

*/