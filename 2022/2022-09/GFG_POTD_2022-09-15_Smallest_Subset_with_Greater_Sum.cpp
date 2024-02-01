// GFG POTD 2022/09/15
// Smallest Subset with Greater Sum
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minSubset(vector<int> &arr, int n){
        long long sum=0, s=0, i;
        for(i=0; i<n; i++){
            sum += arr[i];
        }
        sort(arr.begin(), arr.end());
        for(i=n-1; i>=0; i--){
            s += arr[i];
            if(s>sum-s){
                return n-i;
            }
        }
        return n-1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}

/* Sample Input
2
4
2 17 7 3
4
20 12 18 4

Sample Output
1
2

*/