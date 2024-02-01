// GFG POTD 2023/05/21
// Bus Conductor
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMoves(int n, vector<int> chairs, vector<int> passengers) {
        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());
        
        int moves = 0;
        for(int i = 0; i < n; i++)
            moves += abs(chairs[i] - passengers[i]);
        
        return moves;
    }
};

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> chairs(n), passengers(n);
        for (auto &val: chairs) cin >> val;
        for (auto &val: passengers) cin >> val;
        int ans = sol.findMoves(n, chairs, passengers);
        cout << ans << '\n';
    }
    return 0;
}

/* Sample Input:
2
3
3 1 5
2 7 4
4
2 2 6 6
1 3 2 6

Sample Output:
4
4

*/