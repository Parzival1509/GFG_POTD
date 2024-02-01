// GFG POTD 2022/12/01
// Rearrange Array Alternately

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void rearrange(long long *arr, int n) { 
        int st=0, end=n-1;
        long long max=arr[n-1]+1;
        
        // First Approach
        for(int i=0; i<n; i+=2) {
            int c = arr[end--]%max;
            arr[i] = arr[i]+c*max;
            c = arr[st++]%max;
            arr[i+1] = arr[i+1]+c*max;
        }
        
    //  // Second Approach
    //  for(int i=0; i<n; i++) {
    //      if(i%2 == 0)
    //          arr[i] += (arr[end--]%max)*max;
    //      else
    //          arr[i] += (arr[st++]%max)*max;
    //  }
        
        for(int i=0; i<n; i++)
            arr[i] /= max;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long arr[n];
        for(int i = 0;i<n;i++)
            cin >> arr[i];
        Solution ob;
        ob.rearrange(arr, n);
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " ";
        
        cout << endl;
    }
    return 0; 
}

/* Sample Input
2
6
1 2 3 4 5 6
11
1 2 3 4 5 6 7 8 9 10 11

Sample Output
6 1 5 2 4 3 
11 1 10 2 9 3 8 4 7 5 6 

*/