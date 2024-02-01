// GFG POTD 2023/07/04
// Count the Subarrays Having Product Less Than k
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int count = 0, end = 0;
        long long product = 1;
        
        for (int start = 0; start < n; start++) {
            product *= a[start];
            
            while (product >= k && end <= start) {
                product /= a[end];
                end++;
            }
            count += (start - end + 1);
        }
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

/* Sample Input:
2
4 10
1 2 3 4
7 100
1 9 2 8 6 4 3

Sample Output:
7
16

*/