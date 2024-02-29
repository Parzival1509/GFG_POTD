// GFG POTD 2024/02/15
// Count All Possible Path
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPossible(vector<vector<int>> paths) {
        for(int i = 0; i < paths.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < paths[0].size(); j++)
                cnt += paths[i][j];
            
            if(cnt & 1) return 0;
        }
        
        return 1;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<vector<int>> paths(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> paths[i][j];
        Solution obj;
        cout << obj.isPossible(paths) << endl;
    }
    return 0;
}

/* Sample Input:
2
5
0 1 1 1 1
1 0 0 1 0
1 0 0 1 0
1 1 1 0 1
1 0 0 1 0
4
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0

Sample Output:
1
0

*/