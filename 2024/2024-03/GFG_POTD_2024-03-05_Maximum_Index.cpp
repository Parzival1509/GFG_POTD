// GFG POTD 2024/03/05
// Maximum Index
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(int val, int l, int r, vector<int>& suff) {
        int ind = l - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (suff[mid] < val)
                r = mid - 1;
            else {
                ind = mid;
                l = mid + 1;
            }
        }

        return ind;
    }
    
    int maxIndexDiff(int a[], int n) {
        if (n == 1) return 0;

        // // Approach 1: Binary Search
        // // T.C. = O(N log N), S.C. = O(N)
        // vector<int> suff(n);
        // suff[n - 1] = a[n - 1];
        // for (int i = n - 2; i >= 0; i--)
        //     suff[i] = max(suff[i + 1], a[i]);

        // int res = 0;
        // for (int i = 0; i < n; i++) {
        //     int x = find(a[i], i + 1, n - 1, suff);
        //     res = max(res, x - i);
        // }

        // Approach 2:
        // T.C. = O(N), S.C. = O(N)
        vector<int> v;
        v.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--)
            if (a[i] > a[v.back()])
                v.push_back(i);
        int res = 0;
        for (int i = 0; i < n - 1; i++)
            while (v.size() > 0 && a[i] <= a[v.back()]) {
                res = max(res, v.back() - i);
                v.pop_back();
            }
        
        return res;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int num;
        cin >> num;
        int arr[num];
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}

/* Sample Input
2
2
1 10
9
34 8 10 3 2 80 30 33 1

Sample Output
1
6

*/