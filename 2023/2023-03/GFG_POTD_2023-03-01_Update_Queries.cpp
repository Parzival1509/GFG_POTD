// GFG POTD 2023/03/01
// Update Queries
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> updateQuery(int N,int Q,vector<vector<int>> &U) {
        vector<vector<int>> bit(N+5, vector<int>(35));
        for(auto& q: U) {
            int l = q[0] - 1, r = q[1] - 1, x = q[2];
            for(int i=0; i<32; i++)
                if(x & (1<<i)) {
                    ++bit[l][i];
                    --bit[r+1][i];
                }
        }
        
        for(int i=1; i<N; i++)
            for(int j=0; j<32; j++)
                bit[i][j] += bit[i-1][j];

        vector<int> ans(N);
        for(int i=0; i<N; i++)
            for(int j=0; j<32; j++)
                if(bit[i][j])
                    ans[i] |= (1<<j);
                    
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, q;
        cin>>n>>q;
        vector <vector <int>> u(q, vector <int>(3));
        for(int i=0; i<q; i++)
            cin>>u[i][0]>>u[i][1]>>u[i][2];
        Solution a;
        vector <int> ans = a.updateQuery(n, q, u);
        for(auto j: ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input:
2
3 2
1 3 1
1 3 2
3 2
1 2 1
3 3 2

Sample Output:
3 3 3 
1 1 2 

*/