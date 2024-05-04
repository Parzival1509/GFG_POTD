// GFG POTD 2024/04/14
// Xoring and Clearing
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printArr(int n, int arr[]) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << ' ';
        cout << endl;
    }

    void setToZero(int n, int arr[]) {
        for (int i = 0; i < n; i++)
            arr[i] = 0;
    }

    void xor1ToN(int n, int arr[]) {
        for (int i = 0; i < n; i++)
            arr[i] ^= i;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution obj;
        obj.xor1ToN(n, arr);
        obj.printArr(n, arr);
        obj.setToZero(n, arr);
        obj.printArr(n, arr);
    }
    return 0;
}

/* Sample Input
2
4
10 20 30 40
10
1 2 3 4 5 6 7 8 9 10

Sample Output
10 21 28 43 
0 0 0 0 
1 3 1 7 1 3 1 15 1 3 
0 0 0 0 0 0 0 0 0 0 

*/