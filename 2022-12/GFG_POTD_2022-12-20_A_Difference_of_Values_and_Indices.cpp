// GFG POTD 2022/12/20
// A Difference of Values and Indices
// Medium

#include <bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int maxDistance(int arr[], int n) { 
        int mx1=INT_MIN, mx2=INT_MIN, mn1=INT_MAX, mn2=INT_MAX;
        for(int i=0; i<n; i++) {
            //a[i]>a[j]
            mx1 = max(mx1, arr[i]-i);
            mn1 = min(mn1, arr[i]-i);

            // a[i]<a[j]
            mx2 = max(mx2, arr[i]+i);
            mn2 = min(mn2, arr[i]+i);
        }
        return max(mx1-mn1, mx2-mn2);
    }
};

int main() { 
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.maxDistance(arr, n)<<endl;
    }
}

/* Sample Input
2
3
1 3 -1
4
5 9 2 6

Sample Output
5
8

*/