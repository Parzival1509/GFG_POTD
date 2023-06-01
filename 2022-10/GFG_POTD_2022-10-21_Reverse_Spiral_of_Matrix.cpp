// GFG POTD Reverse Spiral Form of Matrix

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> reverseSpiral(int r, int c, vector<vector<int>> &a){
        vector<int> ans;
        int i=0, j=0, ct=0, rr=0, cc=0;

        while(ct<r*c){
            for(j=0+cc; ct<r*c && j<c-cc; j++){
                ans.push_back(a[i][j]);
                ct++;
            }
            j--;

            for(i=1+rr; ct<r*c && i<r-rr-1; i++){
                ans.push_back(a[i][j]);
                ct++;
            }
            // i--;
            cc++;

            for(j=c-cc; ct<r*c && j>=0+cc; j--){
                ans.push_back(a[i][j]);
                ct++;
            }
            // j++;
            rr++;

            for(i=r-rr; ct<r*c && i>=0+rr; i--){
                ans.push_back(a[i][j]);
                ct++;
            }
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0; i<R*C; i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R, C, a);
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
3 3
9 8 7
6 5 4
3 2 1
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Sample Output
5 6 3 2 1 4 7 8 9 
10 11 7 6 5 9 13 14 15 16 12 8 4 3 2 1 
36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 

*/