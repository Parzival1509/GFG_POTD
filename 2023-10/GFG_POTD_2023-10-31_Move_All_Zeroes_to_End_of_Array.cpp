// GFG POTD 2023/10/31
// Move All Zeroes to End of Array
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void pushZerosToEnd(int arr[], int n) {
        int i = 0;
        for(int j = 0; j < n; j++)
            if(arr[j] != 0)
                swap(arr[i++], arr[j]);
                
        while(i < n)
            arr[i++] = 0;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for(i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for(i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}

/* Sample Input:
2
5
3 5 0 0 4
4
0 0 0 4

Sample Output:
3 5 4 0 0 
4 0 0 0 

*/