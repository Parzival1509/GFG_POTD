// GFG POTD 2024/06/09
// Convert Array Into Zig-Zag fashion
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void zigZag(int n, vector<int>& arr) {
        int i = 0;
        while (i < (n - 1)) {
            if (i % 2 == 0) {
                if (arr[i] < arr[i + 1])
                    i++;
                else {
                    swap(arr[i], arr[i + 1]);
                    i++;
                }
            } else if (i % 2 != 0) {
                if (arr[i] > arr[i + 1])
                    i++;
                else {
                    swap(arr[i], arr[i + 1]);
                    i++;
                }
            }
        }
        
        return;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        ob.zigZag(n, arr);
        for(int i: arr)
            cout << i << ' ';
        cout << endl;
    }
}

/* Sample Input
2
7
4 3 7 8 6 2 1
5
4 7 3 8 2

Sample Output
3 7 4 8 2 6 1 
4 7 3 8 2 

*/