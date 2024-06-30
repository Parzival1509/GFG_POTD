// GFG POTD 2024/06/07
// Maximum Occured Integer
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int> arr(maxx + 2, 0);
        for (int i = 0; i < n; i++) {
            arr[l[i]]++;
            arr[r[i] + 1]--;
        }

        int sum = 0, freq = 0, no = 0;
        for (int i = 0; i < maxx + 2; i++) {
            arr[i] += arr[i] + sum;
            sum = arr[i];
            if (arr[i] > freq) {
                freq = arr[i];
                no = i;
            }
        }

        return no;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int l[n], r[n];
        for (int i = 0; i < n; i++)
            cin >> l[i];

        int maxx = 0;
        for (int i = 0; i < n; i++) {
            cin >> r[i];
            if (r[i] > maxx)
                maxx = r[i];
        }
        Solution ob;
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}

/* Sample Input
2
4
1 4 3 1
15 8 5 4
5
1 5 9 13 21
15 8 12 20 30

Sample Output
4
5

*/