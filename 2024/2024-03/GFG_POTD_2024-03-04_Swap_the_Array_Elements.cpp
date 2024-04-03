// GFG POTD 2024/03/04
// Swap the Array Elements
// Easy

#include <iostream>
using namespace std;

class Solution {
public:
    void swapElements(int arr[], int n) {
        for (int i = 0; i < n - 2; ++i) {
            arr[i + 2] = arr[i + 2] + arr[i];
            arr[i] = arr[i + 2] - arr[i];
            arr[i + 2] = arr[i + 2] - arr[i];
        }
    }
};

int main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        obj.swapElements(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}

/* Sample Input
2
3
1 2 3
5
1 2 3 4 5

Sample Output
3 2 1 
3 4 5 2 1 

*/