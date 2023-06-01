// GFG POTD 2023/03/11
// Yet Another Query Problem
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &q) {
        vector<int> result;
        int j = 0;
        while(num--) {
            unordered_map<int, int> m;
            int l = q[j][0];
            int r = q[j][1];
            int k = q[j][2];
            j++;
            int count = 0;
            for(int i=N-1; i>=l; i--) {
                m[A[i]]++;
                if(i<=r && m[A[i]]==k) count++;
            }
            result.push_back(count);
        }
        return result;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N, num;
        cin>>N>>num;
        vector<int> A(N);
        for(int i=0; i<N; i++)
            cin>>A[i];
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0; i<num; i++)
            for(int j=0; j<3; j++)
                cin>>Q[i][j];

        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele: res)
            cout<<ele<<" ";
        cout<<endl;
    }
}

/* Sample Input:
2
5 3
1 1 3 4 3
0 2 2
0 2 1
0 4 2
5 2
1 1 1 1 1
0 4 2
0 4 1

Sample Output:
2 1 2 
1 1 

*/