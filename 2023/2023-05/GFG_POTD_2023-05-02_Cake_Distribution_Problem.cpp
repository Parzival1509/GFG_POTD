// GFG POTD 2023/05/02
// Cake Distribution Problem
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0);

        while(left < right) {
            int mid = (left + right + 1) / 2;
            int pieces = 0, currentSweetness = 0;
            for(int s: sweetness) {
                currentSweetness += s;
                if(currentSweetness >= mid) {
                    pieces++;
                    currentSweetness = 0;
                }
            }
            if (pieces > K) left = mid;
            else right = mid - 1;
        }
        
        return left;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++)
            cin >> sweetness[i];
        Solution ob;
        int res = ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}

/* Sample Input:
2
6 2
6 3 2 8 7 5
7 3
1 2 4 7 3 6 9

Sample Output:
9
7

*/