// GFG POTD 2024/06/02
// Construct List Using Given Q XOR Queries
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> constructList(int q, vector<vector<int>>& queries) {
        vector<int> res;
        int n = queries.size(), temp = 0;
        for (int i = n - 1; i >= 0; i--)
            if (queries[i][0] == 0)
                res.push_back(queries[i][1] ^ temp);
            else temp ^= queries[i][1];
        
        res.push_back(temp);
        sort(res.begin(), res.end());

        return res;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while (t--) {
        int q;
        cin >> q;
        vector<vector<int>> queries(q, {0, 0});
        for(int i = 0; i < q; i++)
            cin >> queries[i][0] >> queries[i][1];
        vector<int> ans = ob.constructList(q, queries);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

/* Sample Input
2
5
0 6
0 3
0 2
1 4
1 5
3
0 2
1 3
0 5

Sample Output
1 2 3 7 
1 3 5 

*/