// GFG POTD 2024/05/17
// Find Pair Given Differences
// Easy

#include <bits/stdc++.h>
using namespace std;

class Array {
public:
    template <class T> static void input(vector<T>& A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T> static void print(vector<T>& A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution {
public:
    int findPair(int n, int x, vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        if (x == 0) {
            if (s.size() == arr.size())
                return -1;
            return 1;
        }

        for (int i = 0; i < n; i++)
            if (s.find(x + arr[i]) != s.end())
                return 1;

        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        Array::input(arr, n);
        Solution obj;
        int res = obj.findPair(n, x, arr);
        cout << res << endl;
    }
}

/* Sample Input
2
6 78
5 20 3 2 5 80
5 45
90 70 20 80 50

Sample Output
1
-1

*/