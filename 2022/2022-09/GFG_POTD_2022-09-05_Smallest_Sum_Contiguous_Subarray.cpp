// GFG POTD Smallest Sum Contiguous Subarray
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
  int smallestSumSubarray(vector<int>& a){
      int ans=INT_MAX, sum=0;
      for(int i=0; i<a.size(); i++){
        sum += a[i];
        ans = min(ans, sum);
        if(sum>0)
            sum=0;
      }
      return ans;
  }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution ob;
        int ans = ob.smallestSumSubarray(a);
        cout<<ans<<endl;
    }
}