// GFG POTD 2024/05/25
// You and Your Books
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long max_Books(int arr[], int n, int k) {
        long long sum = 0;
        int i = 0;
        while (i < n) {
            long long temp = 0;
            if (arr[i] <= k) {
                while (i < n && arr[i] <= k) {
                    temp += arr[i];
                    i++;
                }
                sum = max(sum, temp);
            }
            i++;
        }

        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++)
            cin >> ar[i];
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

/* Sample Input
2
8 1
3 2 2 3 1 1 1 3
8 2
3 2 2 3 1 1 1 3

Sample Output
3
4

*/