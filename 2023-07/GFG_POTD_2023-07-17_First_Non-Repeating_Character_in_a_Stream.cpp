// GFG POTD 2023/07/17
// First Non-Repeating Character in a Stream
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string FirstNonRepeating(string s) {
        int n = s.length(), j = 0;
        int cnt[26] = {0};
        string ans;
        for(int i = 0; i < n; i++) {
            int ch = s[i] - 'a';
            cnt[ch]++;
            while(j <= i && cnt[s[j] - 'a'] > 1)
                j++;
            
            if(j > i) ans += '#';
            else ans += s[j];
        }
        return ans;
    }

};

int main() {
    int tc;
    cin >> tc;
    while(tc--){
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input:
2
aabc
zz

Sample Output:
a#bb
z#

*/