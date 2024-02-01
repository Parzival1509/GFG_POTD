// GFG POTD 2023/03/24
// Remove and Reverse
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeReverse(string s) {
        vector<int> hsh(123, 0);

        int i = 0, j = s.size()-1, f = 0;
        for(auto x: s)
            hsh[x]++;

        while(i < j) {
            if(f == 0) {
                if(hsh[s[i]] > 1) {
                    hsh[s[i]]--;
                    s.erase(s.begin()+i);
                    f = 1;
                }
                else i++;
            }
            else {
                if(hsh[s[j]] > 1) {
                    hsh[s[j]]--;
                    s.erase(s.begin()+j);
                    f = 0;
                }
                else j--;
            }
        }
        
        if(f) reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}

/* Sample Input:
3
abab
dddd
xnkkqluhwdjbrrvbuzcyyntjpkfzpxmyrjed

Sample Output:
ba
d
emxfkpjtnyczubvrdwhlq

*/