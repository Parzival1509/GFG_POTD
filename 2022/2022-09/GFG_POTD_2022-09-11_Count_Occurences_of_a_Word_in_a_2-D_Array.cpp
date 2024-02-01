// GFG POTD Count Occurences of a Word in a 2-D Array
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool visited[51][51];
    int sol(vector<vector<char>> &arr, string t, int i, int j, int index){
        if(visited[i][j]) return 0;

        int n = arr.size() , m = arr[0].size();
        if(i >= n || j >= m || i < 0 || j < 0)
         return 0;

        if(arr[i][j] == t[index] and index == t.size()-1)
            return 1;

        visited[i][j] = true;
        int a = 0 ;

        if(arr[i][j] == t[index]){
          a = sol(arr,t,i+1,j,index+1) + sol(arr,t,i,j+1,index+1) + sol(arr,t,i-1,j,index+1) + sol(arr,t,i,j-1,index+1) ;
        }
        visited[i][j] = false;
        return a;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        memset(visited, false, sizeof visited);
        int ct = 0;
        for(int i=0; i<mat.size(); ++i){
            for(int j=0; j<mat[0].size(); ++j){
                int a = sol(mat, target, i, j, 0);
                ct += a; 
            }
        }
        return ct;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

/* Sample Input
1
4 5
SNBSN
BAKEA
BKBBK
SEBSE
SNAKES

Sample Output
3

*/