// GFG POTD 2022/09/28
// Fitting the Array
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isFit(int arr[], int brr[], int n){
        sort(arr, arr+n);
        sort(brr, brr+n);
        for(int i=0; i<n; i++){
            if(arr[i]>brr[i])
                return false;
        }
        return true;
    }
};

int main() {
    int i, j, z, t, n, flag;
    cin>>t;
    for(z=0; z<t; z++) {
        flag=0;
        cin>>n;
        int arr[n+1], brr[n+1];
        for(i=0; i<n; i++)
            cin>>arr[i];
        for(i=0; i<n; i++)
            cin>>brr[i];
        Solution ob;
        if(ob.isFit(arr, brr, n))
            cout<<"YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

/* Sample Input
2
4
7 5 3 2
5 4 8 7
3
1 2 4
1 2 3

Sample Output
YES
NO

*/