// GFG POTD 2023/11/25
// Shuffle Integers
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shuffleArray(int arr[], int n) {
        int maxval = 1e4;
        
        for(int i = 2, j = 1; i < n; i += 2, j++) 
            arr[i] = (arr[j] % maxval) * maxval + arr[i];
        for(int i = 1, j = n / 2; i < n; i += 2, j++)
            arr[i] = (arr[j] % maxval) * maxval + arr[i];
        for(int i = 1; i < n; i++)
            arr[i] /= maxval;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n] ;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        ob.shuffleArray(a, n);
        for(int i = 0; i < n; i++) 
            cout << a[i] << " ";
        cout << "\n";
    }

    return 0;
}

/* Sample Input:
2
4
1 2 9 15
6
1 2 3 4 5 6

Sample Output:
1 9 2 15 
1 4 2 5 3 6 

*/