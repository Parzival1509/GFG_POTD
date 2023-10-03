// GFG POTD 2023/09/28
// Wave Array
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void convertToWave(int n, vector<int>& arr) {
        for(int i = 1; i < n; i += 2)
            swap(arr[i], arr[i - 1]);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin >> i;
        Solution ob;
        ob.convertToWave(n, arr);
        for(int i: arr)
            cout << i << ' ';
        cout << endl;
    }
    
    return 0;
}

/* Sample Input:
2
5
1 2 3 4 5
6
2 4 7 8 9 10

Sample Output:
2 1 4 3 5 
4 2 8 7 10 9 

*/