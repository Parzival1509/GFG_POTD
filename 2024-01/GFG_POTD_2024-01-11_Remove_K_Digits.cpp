// GFG POTD 2024/01/11
// Remove K Digits
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string s, int k) {
        deque<char> dq;
        int n = s.length();
        for(int i = 0; i < n; i++) {
            while(!dq.empty() && dq.back() > s[i] && k > 0) {
                if(dq.back() != '0')
                    k--;
                dq.pop_back();
            }
            dq.push_back(s[i]);
        }
        
        while(k-- && !dq.empty())
            dq.pop_back();
        while(!dq.empty() && dq.front() == '0')
            dq.pop_front();
            
        if(dq.size() == 0) return "0";
         
        string ans;
        for(auto &x: dq)
             ans.push_back(x);

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }

    return 0;
}

/* Sample Input:
2
149811 3
1002991 3

Sample Output:
111
21

*/