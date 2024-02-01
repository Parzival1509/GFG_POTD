// GFG POTD Save Your Life

#include <bits/stdc++.h> 
using namespace std; 

class Solution{
public:
    int hsh[100001];
    int maximizeSum(int a[], int n){
        memset(hsh, 0, sizeof hsh);
        long long sum=0;
        for(int i=1; i<=n; i++)
            hsh[a[i]]++;
        // 
        // for(int i=1; i<=a[n-1]+1; i++)
        //     cout<<hsh[i]<<' ';
        // cout<<endl;

        for(int i=a[n-1]; i>0; i--){
            if(hsh[a[i]]>0){
                sum += hsh[a[i]]*i;
                if(hsh[a[i]-1]>0)
                    hsh[a[i]-1] -= hsh[a[i]];
            }
        }
        return sum;
    }
};

int main(){
    int t;
    cin>> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        for(int i=0;i<n;i++)
            cout<<arr[i]<<' ';
        cout<<endl;
        Solution ob;
        cout << ob.maximizeSum(arr, n) << endl << endl;
    }
}

/* Sample Input
3
6
1 2 2 2 3 4
3
1 2 3
20
9 15 9 3 8 4 6 17 7 11 17 7 3 18 13 9 7 12 2 8

Sample Output
de
dbfbsdbf

*/