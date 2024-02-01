// GFG POTD 2023/12/23
// Count More Than n/k Occurences
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
        
        int ans = 0;
        for(auto it: mp)
           if(it.second > n / k) ans++;
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, i, k;
        cin >> n >> k;
        int arr[n];
        for(i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }

    return 0;
}

/* Sample Input:
2
8 4
3 1 2 2 1 2 3 3
4 3
2 3 3 2

Sample Output:
2
2

*/