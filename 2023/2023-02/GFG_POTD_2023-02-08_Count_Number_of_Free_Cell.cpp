// GFG POTD 2023/02/08
// Count Number of Free Cell
// Easy

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<ll> countZero(int n, int k, vector<vector<int>>& arr) {
        vector<ll> ans;
        vector<int> rows(n, 0), cols(n, 0);
        ll rct = 0, cct = 0, tmp = n*n;

        for(auto task: arr) {
            int r = task[0]-1, c = task[1]-1;

            // if(rows[r]==1 and cols[c]==1)
            //     ans.push_back(tmp);
            // else if(rows[r]==1) {
            //     cols[c] = 1;
            //     cct++;
            //     tmp = tmp - n + rct;
            //     ans.push_back(tmp);
            // }
            // else if(cols[c] == 1) {
            //     rows[r] = 1;
            //     rct++;
            //     tmp = tmp - n + cct;
            //     ans.push_back(tmp);
            // }
            // else {
            //     rows[r] = 1;
            //     cols[c] = 1;
            //     tmp = tmp - n + rct - n + cct + 1;
            //     rct++;
            //     cct++;
            //     ans.push_back(tmp);
            // }

            if(!rows[r]) {
                rows[r] = 1;
                tmp -= n-cct;
                rct++;
            }
            if(!cols[c]) {
                cols[c] = 1;
                tmp -= n-rct;
                cct++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<vector<int>> arr(k, vector<int>(2));
        for(int i=0; i<k; i++) {
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<ll> ans = ob.countZero(n, k, arr);
        
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;    
    }
    return 0;
}

/* Sample Input:
2
2 2
1 2
1 1
3 3
2 2
2 3
3 2

Sample Output:
1 0 
4 2 1 

*/