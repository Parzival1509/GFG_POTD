// GFG POTD 2023/03/26
// Frogs and Jumps
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        vector<int> vis(leaves + 1);
        for(int i = 0; i < n; i++)
            if(frogs[i] <= leaves and !vis[frogs[i]])
                for(int j = frogs[i]; j <= leaves; j += frogs[i]) 
                    vis[j] = 1;
        
        int count = 0;
        for(int i = 1; i <= leaves; i++)
            if(!vis[i]) count++;
        
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++)
            cin >> frogs[i];
        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}

/* Sample Input:
3
3 4
3 2 4
3 6
1 3 5
3 4
2 3 4

Sample Output:
1
0
1

*/