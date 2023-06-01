// GFG POTD Minimum Exchange
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MinimumExchange(vector<vector<char>>matrix){
        int ab=0, ba=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[i].size(); j++){
                if((i+j)%2==0 && matrix[i][j]=='A'){
                    ba++;
                }
                else if((i+j)%2==0 && matrix[i][j]=='B'){
                    ab++;
                }
                else if((i+j)%2==1 && matrix[i][j]=='A'){
                    ab++;
                }
                else if((i+j)%2==1 && matrix[i][j]=='B'){
                    ba++;
                }
            }
        }
        if(ab%2==1){
            return ba/2;
        }
        else if(ba%2==1){
            return ab/2;
        }
        return min(ab/2, ba/2);
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>>matrix(n, vector<char>(m,'x'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++)
                cin >> matrix[i][j];
        }
        Solution obj;
        int ans = obj.MinimumExchange(matrix);
        cout << ans <<"\n";
    }
    return 0;
}

/* Sample Input
2
3 4
AABA
BABA
BBAB
2 2
AB
BA

Sample Output
4
0

*/