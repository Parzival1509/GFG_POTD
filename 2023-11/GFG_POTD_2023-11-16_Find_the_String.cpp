// GFG POTD 2023/11/16
// Find the String
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mp;

    void dfs(string curr, string &ans, int k) {
        for(int i = k - 1; i >= 0; i--) {
            string temp = curr.substr(1) + (char)(i + '0');
            if(!mp[temp]) {
                mp[temp]++;
                ans += (i + '0');
                dfs(temp, ans, k);
                return;
            }
        }
    }
    
    string findString(int n, int k) {
        string ans = "", temp = "";
        
        for(int i = 0; i < n; i++)
            ans += '0';
        temp += ans;
        mp[temp]++;
        dfs(temp, ans, k);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok = 1;
        for(auto i: ans)
            if(i < '0' || (i > K - 1 + '0'))
                ok = 0;
        if(!ok) {
            cout << -1 << endl;
            continue;
        }

        unordered_set<string> st;
        for(int i = 0; i + N - 1 < ans.size(); i++)
            st.insert(ans.substr(i, N));
        
        int tot = 1;
        for(int i = 1; i <= N; i++)
            tot *= K;
        
        if(st.size() == tot)
            cout << ans.size() << endl;
        else cout << -1 << endl;
    }

    return 0;
}

/* Sample Input:
2
2 2
2 3

Sample Output:
5
10

*/