// GFG POTD 2022/11/03
// Array Removals

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int removals(vector<int>& arr, int k){
        sort(arr.begin(), arr.end());
        int i=0, j=0, mx=0;
        while(j<arr.size()){
            if(arr[j]-arr[i] <= k) j++;
            else if(i<j) i++;
            mx=max(mx, j-i);
        }
        return arr.size()-mx;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        int ans = ob.removals(arr,k);
        cout<<ans<<endl;
    }
}

/* Sample Input
2
9 4
1 3 4 9 10 11 12 17 20
5 2
1 5 6 2 8

Sample Output
5
3

*/