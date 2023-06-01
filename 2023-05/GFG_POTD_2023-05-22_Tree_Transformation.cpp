// GFG POTD 2023/05/22
// Tree Transformation
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int N, vector<int> p) {
        p[0] = 0;
        unordered_map<int, int> mp;
        for(auto i: p) mp[i]++;
        return mp.size() - 1;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        vector<int> p(N);
        for(int i = 0; i < N; i++)
            cin >> p[i];
        Solution obj;
        cout << obj.solve(N, p) << "\n";
    }
}

/* Sample Input:
2
5
-1 0 0 1 1
8
-1 0 0 0 0 2 2 5

Sample Output:
1
2

*/