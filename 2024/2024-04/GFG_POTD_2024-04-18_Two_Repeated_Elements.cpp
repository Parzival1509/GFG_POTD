// GFG POTD 2024/04/18
// Two Repeated Elements
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoRepeated(int arr[], int n) {
        vector<int> res;
        for (int i = 0; i < n + 2; i++) {
            if (arr[abs(arr[i])] < 0)
                res.push_back(abs(arr[i]));
            else arr[abs(arr[i])] = -arr[abs(arr[i])];
        }

        return res;
    }
};

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int a[n + 2];
        for (int i = 0; i < n + 2; i++)
            cin >> a[i];
        Solution obj;
        vector<int> res;
        res = obj.twoRepeated(a, n);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}

/* Sample Input
2
2
1 2 2 1
4
1 2 1 3 4 3

Sample Output
2 1
1 3

*/