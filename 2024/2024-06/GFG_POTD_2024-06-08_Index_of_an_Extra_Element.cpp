// GFG POTD 2024/06/08
// Index of an Extra Element
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findExtra(int n, int arr1[], int arr2[]) {
        int i = 0;
        for(; i < n - 1; i++)
            if(arr1[i] != arr2[i])
                break;
        
        return i;        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        for (int i = 0; i < n - 1; i++)
            cin >> arr2[i];
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}

/* Sample Input
2
7
2 4 6 8 9 10 12
2 4 6 8 10 12
6
3 5 7 8 11 13
3 5 7 11 13

Sample Output
4
3

*/