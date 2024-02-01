// GFG POTD 2022/09/29
// Sort an array of 0s, 1s and 2s
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    void sort012(int a[], int n){
        int i,p=0;
        for(i=0; i<n; i++)
            if(a[i]==0){
                swap(a[p], a[i]);
                p++;
            }
        for(i=p; i<n; i++)
            if(a[i]==1){
                swap(a[p], a[i]);
                p++;
            }
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        Solution ob;
        ob.sort012(a, n);
        for(int i=0;i<n;i++)
            cout << a[i]  << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
3
0 1 0
5
0 2 1 2 0

Sample Output
0 0 1 
0 0 1 2 2 

*/