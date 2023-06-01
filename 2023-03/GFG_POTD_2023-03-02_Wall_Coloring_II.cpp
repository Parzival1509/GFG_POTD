// GFG POTD 2023/03/02
// Wall Coloring II
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>> &cost) {
        int n = cost.size(), k = cost[0].size();
        if(k == 1) {
            if(n == 1) return cost[0][0];
            return -1;
        }
        
        pair<int, int> mini = {INT_MAX, -1}, smini = {INT_MAX, -1};
        for(int i=0; i<k; i++) {
            if(cost[0][i] < mini.first) {
                smini = mini;
                mini = {cost[0][i], i};
            }
            else if(cost[0][i] < smini.first)
                smini = {cost[0][i], i};
        }
        
        for(int i=1; i<n; i++) {
            pair<int, int> curMini = {INT_MAX, -1}, curSmini = {INT_MAX, -1};
            
            for(int j=0; j<k; j++) {
                int x = cost[i][j];
                if(j != mini.second)
                    x += mini.first;
                else
                    x += smini.first;
                    
                if(x < curMini.first) {
                    curSmini = curMini;
                    curMini = {x, j};
                }
                else if(x < curSmini.first)
                    curSmini = {x, j};
            }
            mini = curMini;
            smini = curSmini;
        }
        return mini.first;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}

/* Sample Input:
2
4 3
1 5 7
5 8 4
3 2 9
1 2 4
5 1
5
4
9
2
1

Sample Output:
8
-1

*/