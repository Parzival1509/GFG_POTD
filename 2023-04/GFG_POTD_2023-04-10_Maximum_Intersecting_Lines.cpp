// GFG POTD 2023/04/10
// Maximum Intersecting Lines
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int, int> endpoints;
        for (auto& line: lines) {
            endpoints[line[0]]++;
            endpoints[line[1] + 1]--;
        }

        int intersections = 0, activeLines = 0;
        for (auto& count: endpoints) {
            activeLines += count.second;
            intersections = max(intersections, activeLines);
        }
        return intersections;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < 2; j++)
                cin >> mat[i][j];
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}

/* Sample Input:
2
4
1 3
2 3
1 2
4 4
3
1 3
5 6
3 4

Sample Output:
3
2

*/