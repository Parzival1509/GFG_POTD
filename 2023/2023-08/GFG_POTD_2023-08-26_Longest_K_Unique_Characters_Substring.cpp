// GFG POTD 2023/08/26
// Longest K Unique Characters Substring
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string s, int k) {
        int n = s.size(), start = 0, end = 0, ct = 0, ans = -1;

        // // Approach 1: Without Map (Using Vector)
        // vector<int> hsh(128, 0);
        // while(end < n) {
        //     if(++hsh[s[end++]] == 1)
        //         ct++;
        //     while(ct > k)
        //         if(--hsh[s[start++]] == 0)
        //             ct--;
        //     if(ct == k)
        //         ans = max(ans, end - start);
        // }

        // Approach 2: Using Map
        map<char, int> hsh;

        while(end < n) {
            if(hsh.size() <= k) {
                hsh[s[end]]++;
                end++;
            }
            if(hsh.size() == k)
                ans = max(ans, end - start);
            while(hsh.size() > k) {
                hsh[s[start]]--;
                if(hsh[s[start]] == 0)
                    hsh.erase(s[start]);
                start++;
            }
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

/* Sample Input:
2
aabacbebebe 3
aaaa 2

Sample Output:
7
-1

*/