// GFG POTD 2023/10/05
// Count Number of Substrings
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(string &s, int k) {
        int i = 0, j = 0, dct = 0;
        long long ans = 0;
        
        vector<int> hsh(26, 0);
        while(j < s.size()) {
            hsh[s[j] - 'a']++;
            if(hsh[s[j] - 'a'] == 1)
                dct++;
            
            // Decreasing window size
            while(dct > k) {
                hsh[s[i] - 'a']--;
                if(hsh[s[i] - 'a'] == 0)
                    dct--;
                i++;
            }
            j++;
            ans += j - i + 1;
        }
        
        return ans;
    }

    long long substrCount (string s, int k) {
        return solve(s, k) - solve(s, k - 1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        Solution ob;
        cout <<ob.substrCount (s, k) << endl;
    }
}

/* Sample Input:
2
aba 2
abaaca 1

Sample Output:
3
7

*/