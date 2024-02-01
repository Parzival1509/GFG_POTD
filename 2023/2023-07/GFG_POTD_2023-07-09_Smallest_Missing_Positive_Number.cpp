// GFG POTD 2023/07/09
// Smallest Positive Missing Number
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(int arr[], int n) {
        int i = 0;
        while(i < n) {
            if(arr[i] > 0 and arr[i] <= n and (arr[i] != arr[arr[i] - 1])) {
                swap(arr[i], arr[arr[i] - 1]);
            }
            else i++;
        }
        
        for(int i = 0; i < n; i++)
            if(arr[i] != i + 1)
                return i + 1;
        
        return n + 1;
    } 
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0; 
}

/* Sample Input:
3
5
1 2 3 4 5
5
0 -10 1 3 -20
13
0 1 2 3 4 5 6 7 8 9 10 11 12

Sample Output:
6
2
13

*/