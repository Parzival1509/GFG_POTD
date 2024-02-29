// GFG POTD 2024/02/17
// Does Array Represent Heap
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMaxHeap(int arr[], int n) {
        for(int i = 0; i < n / 2; i++) {
            if((2 * i + 1 < n && arr[i] < arr[2 * i + 1]) || (2 * i + 2 < n && arr[i] < arr[2 * i + 2]))
                return false;
        }
        
        return true;  
    }
};

int main() {    
    int t;
    cin >> t;
    while(t--) {
       int n;
       cin >> n;
       int a[4 * n] = {0};
       for(int i = 0; i < n; i++)
           cin >> a[i];
       Solution ob;
       cout << ob.isMaxHeap(a, n) << endl;
    }

    return 0;
}

/* Sample Input:
2
6
90 15 10 7 12 2
6
9 15 10 7 12 11

Sample Output:
1
0

*/