// GFG POTD 2023/12/10
// Subarray with 0 Sum
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subArrayExists(int arr[], int n) {
        for(int i = 0; i < n; i++) {
            int sum = 0;
            if(arr[i] == 0) return true;

            for(int j = i; j < n; j++) {
                sum += arr[j];
                if(sum == 0) return true;
            }
        }
        
        return false;
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
        Solution obj;
        if(obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}

/* Sample Input:
2
5
4 2 -3 1 6
5
4 2 0 1 6

Sample Output:
Yes
Yes

*/