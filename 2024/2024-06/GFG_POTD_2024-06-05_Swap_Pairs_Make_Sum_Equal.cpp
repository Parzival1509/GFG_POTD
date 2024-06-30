// GFG POTD 2024/06/05
// Swap Pairs Make Sum Equal
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryrSearch(int* arr, int n, int target) {
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target)
                return mid;

            if (arr[mid] < target)
                low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }

    int findSwapValues(int a[], int n, int b[], int m) {
        sort(a, a + n);
        sort(b, b + m);

        int sumA = 0, sumB = 0;
        for (int i = 0; i < n; i++)
            sumA += a[i];
        for (int i = 0; i < m; i++)
            sumB += b[i];

        if (sumA == sumB)
            return 1;

        int diff = sumA - sumB;
        if (diff % 2 != 0)
            return -1;

        int target = diff / 2;
        for (int i = 0; i < n; i++) {
            int find = a[i] - target;
            if (binaryrSearch(b, m, find) != -1)
                return 1;
        }

        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        Solution ob;
        cout << ob.findSwapValues(a, n, b, m) << "\n";
    }
    return 0;
}

/* Sample Input
2
6 4
4 1 2 1 1 2
3 6 3 3
4 4
5 7 4 6
1 2 3 8

Sample Output
1
1

*/