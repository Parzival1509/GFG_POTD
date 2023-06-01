// GFG POTD 2022/08/22
// Immediate Smaller Element
// Basic

#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
    void immediateSmaller(int *arr, int n) {
        for(int i=0; i<n-1; i++){
            if(arr[i]>arr[i+1])
                arr[i]=arr[i+1];
            else
                arr[i]=-1;
        }
        arr[n-1]=-1;
    }

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/* Sample Input
2
5
4 2 1 5 3
6
5 6 2 3 1 7

Sample Output
2 1 -1 3 -1 
-1 2 -1 1 -1 -1 

*/