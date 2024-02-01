// GFG POTD 2023/05/31
// Frequency Game
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int LargButMinFreq(int arr[], int n) {
        map<int, int> hsh;

        for(int i = 0; i < n; i++)
            hsh[arr[i]]++;
        
        int prev_count = INT_MAX, prev_no = 0;
        for(auto itr: hsh)
            if(itr.second <= prev_count) {
                prev_count = itr.second;
                prev_no = max(itr.first, prev_no);
            }
        
        return prev_no;
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
        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}

/* Sample Input:
2
5
2 2 5 50 1
4
3 3 5 5

Sample Output:
50
5

*/