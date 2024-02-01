// GFG POTD 2023/04/14
// Remove the Balls
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<int> c, r;
        for(int i=0; i<n; i++) {
            if(c.empty() || color[i] != c.top() || radius[i] != r.top()) {
                c.push(color[i]);
                r.push(radius[i]);
            }
            else if(color[i] == c.top() && radius[i] == r.top()) {
                c.pop();
                r.pop();
            }
        }
        return c.size();
    }
};

int main() {
    int T;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin>>n;
        vector<int> color(n, 0), radius(n, 0);
        for(auto &i: color)
            cin>>i;
        for(auto &i: radius)
            cin>>i;
        cout<<ob.finLength(n, color, radius)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
2 2 5
3 3 4
4
1 3 3 1
2 5 5 2

Sample Output:
1
0

*/