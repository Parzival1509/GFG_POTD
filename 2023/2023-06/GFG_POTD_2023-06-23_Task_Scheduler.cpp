// GFG POTD 2023/06/23
// Task Scheduler
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        int mx = 0, ct = 0;
        
        map<char, int> mp;
        for(auto it: tasks) {
            mp[it]++;
            mx = max(mp[it], mx);
        }
        
        for(auto it: mp) {
            if(it.second == mx)
            ct++;
        }
        
        int ans = max(N, ct + ((mx - 1) * (K + 1)));
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, K;
        cin >> N >> K;
        vector<char> tasks(N);
        for(int i = 0; i < N; i++)
            cin >> tasks[i];
        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}

/* Sample Input:
2
6 2 
A A A B B B
12 2
A A A A A A B C D E F G

Sample Output:
8
16

*/