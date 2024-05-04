// GFG POTD 2024/04/21
// Three Way Partitioning
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void threeWayPartition(vector<int>& array, int a, int b) {
        int n = array.size(), low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            if (array[mid] < a) {
                swap(array[low], array[mid]);
                low++;
                mid++;
            } else if (array[mid] > b) {
                swap(array[mid], array[high]);
                high--;
            } else
                mid++;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, a, b;
        cin >> N >> a >> b;

        vector<int> array(N);
        unordered_map<int, int> ump;
        for (int i = 0; i < N; i++) {
            cin >> array[i];
            ump[array[i]]++;
        }

        vector<int> original = array;

        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0, kk2 = 0, kk3 = 0;
        for (int i = 0; i < N; i++) {
            if (original[i] > b)
                k3++;
            else if (original[i] <= b and original[i] >= a)
                k2++;
            else if (original[i] < b)
                k1++;
        }

        Solution ob;
        ob.threeWayPartition(array, a, b);
        for (int i = 0; i < k1; i++)
            if (array[i] < b)
                kk1++;
        for (int i = k1; i < k1 + k2; i++)
            if (array[i] <= b and array[i] >= a)
                kk2++;
        for (int i = k1 + k2; i < k1 + k2 + k3; i++)
            if (array[i] > b)
                kk3++;
        
        bool ok = 0;
        if (k1 == kk1 and k2 == kk2 and k3 == kk3)
            ok = 1;

        for (int i = 0; i < array.size(); i++)
            ump[array[i]]--;
        for (int i = 0; i < array.size(); i++)
            if (ump[array[i]] != 0)
                ok = 0;
        
        if (ok)
            cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

/* Sample Input
2
5 1 2
1 2 3 3 4
6 1 3
1 4 3 6 2 1

Sample Output
1
1

*/