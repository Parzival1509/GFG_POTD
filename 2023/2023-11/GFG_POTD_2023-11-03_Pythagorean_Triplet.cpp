// GFG POTD 2023/11/03
// Pythagorean Triplet
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkTriplet(int arr[], int n) {
        // // Approach 1: Using map
        // unordered_map<int, int> m;
        // for(int i = 0; i < n; i++)
        //     m[arr[i] * arr[i]]++;
        
        // for(int i = 0; i < n - 1; i++)
        //     for(int j = i + 1; j < n; j++)
        //         if(m.count((arr[i] * arr[i]) + (arr[j] * arr[j])))
        //             return true;
        
        // Approach 2: Using Two Pointers
        int ans[n];
        for(int i = 0; i < n; i++)
            ans[i] = arr[i] * arr[i];
       
        sort(ans, ans + n);
        for(int i = n - 1; i > 1; i--) {
            int ele = i, l = 0, r = i-1;
            while(l < r) {
                if(ans[l] + ans[r] == ans[ele]) return true;
                
                if(ans[l] + ans[r] > ans[ele]) r--;
                else l++;
            }
        }

        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

/* Sample Input:
2
5
3 2 4 6 5
3
3 8 5

Sample Output:
Yes
No

*/