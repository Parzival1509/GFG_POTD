// GFG POTD 2023/11/28
// Sum of Dependencies in a Graph
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfDependencies(vector<int> adj[], int V) {
        int sum = 0;
        for(int i = 0; i < V; i++)
            sum += adj[i].size();
            
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<int> v[N];
        for(int i = 0; i < M; i++) {
            cin >> x >> y;
            v[x].push_back(y);
        }
        Solution ob;
        cout << ob.sumOfDependencies(v, N) << "\n";
    }
}

/* Sample Input:
2

4 4
0 2
0 3
1 3
2 3

4 3
0 3
0 2
0 1


Sample Output:
4
3

*/