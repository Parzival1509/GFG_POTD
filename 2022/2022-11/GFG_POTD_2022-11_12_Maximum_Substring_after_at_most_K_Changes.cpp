// GFG POTD 2022/11/12
// Maximum Substring after at most K Changes
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k){
        int mxf=0, mxlen=0, l=0, r=0;
        unordered_map<char, int> hsh;
        while(r<s.size()){
            hsh[s[r]]++;
            mxf = max(mxf, hsh[s[r]]);
            if(r-l+1-mxf > k){
                hsh[s[l]]--;
                l++;
            }
            mxlen = max(mxlen, r-l+1);
            r++;
        }
        return mxlen;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution obj;
        int ans = obj.characterReplacement(s, k);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
ABAB 2
ADBD 1

Sample Output
4
3

*/