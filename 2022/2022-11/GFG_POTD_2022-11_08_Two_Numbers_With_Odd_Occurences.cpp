// GFG POTD 2022/11/08
// Two Numbers With Odd Occurences

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<long long int> twoOddNum(long long int a[], long long int n){
        long long int xx=0, x=0, y=0, rsbm;
        vector<long long int> ans;
        for(int i=0; i<n; i++)
            xx = xx^a[i];
        rsbm = xx&(-xx);
        for(int i=0; i<n; i++){
            if((a[i]&rsbm) == 0)
                x = x^a[i];
            else
                y = y^a[i];
        }
        if(x>y){
            ans.push_back(x);
            ans.push_back(y);
        }
        else{
            ans.push_back(y);
            ans.push_back(x);
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
8
4 2 4 5 2 3 3 1
8
1 7 5 7 5 4 7 4

Sample Output
5 1 
7 1 

*/