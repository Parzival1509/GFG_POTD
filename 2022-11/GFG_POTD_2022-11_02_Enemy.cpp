// GFG POTD 2022/11/02
// Enemy

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int largestArea(int n, int m, int k, vector<vector<int>> &e){
        if(k==0)
            return m*n;
        vector<int> rows(n, 0), cols(m, 0);
        for(int i=0; i<k; i++){
            rows[e[i][0]-1] = -1;
            cols[e[i][1]-1] = -1;
        }
        int mxr=0, cr=0, mxc=0, cc=0;
        for(int i=0; i<n; i++){
            if(rows[i] != -1)
                cr++;
            else
                cr=0;
            if(cr>mxr)
                mxr=cr;
        }
        for(int i=0; i<m; i++){
            if(cols[i] != -1)
                cc++;
            else
                cc=0;
            if(cc>mxc)
                mxc=cc;
        }
        return mxr*mxc;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k, vector<int>(2));
        for(int i=0; i<k; i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n, m, k, e)<<endl;
    }
    return 0;
}

/* Sample Input
3
2 2 1
2 2
3 3 1
3 3
4 9 2
2 1
3 3

Sample Output
1
4
10

*/