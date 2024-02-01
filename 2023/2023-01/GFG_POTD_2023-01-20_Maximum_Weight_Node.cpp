// GFG POTD 2023/01/20
// Maximum Weight Node
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWeightCell(int N, vector<int> edge) {
        vector<int> inDig(N, 0);
        for(int i=0; i<N; i++) {
            if(edge[i] == -1) continue;
            inDig[edge[i]] += i;
        }
        int maxi = INT_MIN, ans = 0;
        for(int i=0; i<N; i++) {
            if(maxi < inDig[i]){
                maxi = inDig[i];
                ans = i;
            }
            if(maxi == inDig[i]) ans=i;
          
        }
        return ans; 
    }
};

int main(){
   int tc;
   cin >> tc;
    while(tc--) {
        int N;
        cin >> N;
        vector<int> Edge(N);
        for(int i=0; i<N; i++)
            cin>>Edge[i];
        Solution obj;
        int ans = obj.maxWeightCell(N, Edge);
        cout<<ans<<endl;
    }
    return 0;
}

/* Sample Input
2
1
-1
4
2 0 -1 2

Sample Output
0
2

*/