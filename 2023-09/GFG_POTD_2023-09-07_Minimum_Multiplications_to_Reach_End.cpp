// GFG POTD 2023/09/07
// Minimum Multiplications to Reach End
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end)  return 0;
        
        int mod = 100000;
        priority_queue<pair<int, int>> q;
        vector<int> prod(mod, INT_MAX);
        q.push({0, start});
        prod[start] = 0;
        
        while(!q.empty()) {
            int steps = -q.top().first, node = q.top().second;
            q.pop();
            
            for(auto nnode: arr) {
                int mult = (node * nnode) % mod;
                if(prod[mult] != INT_MAX) continue;
                
                prod[mult] = steps + 1;
                if(mult == end)
                    return steps + 1;
                
                q.push({-steps - 1, mult});
            }
        }
        
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, start, end;
        cin >> n >> start >> end;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

/* Sample Input:
2
3 3 30
2 5 7
3 7 66175
3 4 65

Sample Output:
2
4

*/