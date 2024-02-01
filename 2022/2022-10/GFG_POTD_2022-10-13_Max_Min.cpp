// GFG POTD 2022/10/13
// Max Min
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findSum(int a[], int n){
        long mn=a[0], mx=a[0];
        for(int i=1; i<n; i++){
            if(mn>a[i])
                mn=a[i];
            if(mx<a[i])
                mx=a[i];
        }
        return mn+mx;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
          cin>>arr[i];
        Solution ob;  
        int ans=ob.findSum(arr, n);
        cout<<ans;
        cout<<"\n";
    }
    return 0;
}

/* Sample Input
2
4
1 3 4 1
5
-2 1 -4 5 3

Sample Output
5
1

*/