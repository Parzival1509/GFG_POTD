// GFG POTD 2023/03/29
// Count the Substrings
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstring(string S) {
        map<int, int> mp;
        mp[0] = 1;
        int ans = 0, sum = 0;
        for (char ch: S) {
            int val;
            if (isupper(ch)) val = 1;
            else val = -1;
            sum += val;
            if (mp.find(sum) != mp.end())
                ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}

/* Sample Input:
2
gEEk
WomensDAY

Sample Output:
3
4

*/