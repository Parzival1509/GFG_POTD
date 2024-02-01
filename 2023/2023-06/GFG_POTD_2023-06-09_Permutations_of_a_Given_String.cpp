// GFG POTD 2023/06/09
// Permutations of a Given String
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1:
    void fun(int index, vector<string> &ans, string s) {
        if(index == s.length()) {
            for(int i = 0; i < ans.size(); i++)
               if(ans[i] == s) return;
            ans.push_back(s);
            return;
        }
        for(int i = index; i < s.length(); i++) {
            swap(s[index],s[i]);
            fun(index + 1, ans, s);
            swap(s[index], s[i]);
        }
    }
    
    vector<string>find_permutation(string S) {
        vector<string> ans;
        fun(0, ans, S);
        sort(ans.begin(), ans.end());
        return ans;
    }

    // // Approach 2:
    // void perm(string &s, int idx, vector<string>& ans, map<char, int>& mp) {
    //     if(idx == s.length()) {
    //         ans.push_back(s);
    //         return;
    //     }
        
    //     for(auto entry: mp) {
    //         char c = entry.first;
    //         int cnt = entry.second;
    //         if(cnt == 0) continue;
            
    //         mp[c]--;
    //         s[idx] = c;
    //         perm(s, idx + 1, ans, mp);
    //         mp[c]++;
    //     }
    // }

    // vector<string> find_permutation(string S) {
    //     map<char, int> mp;
    //     for(char c: S)
    //         mp[c]++;
        
    //     vector<string> ans;
    //     perm(S, 0, ans, mp);
    //     return ans;
    // }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for(auto i: ans)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}

/* Sample Input:
2
ABC
ABSG

Sample Output:
ABC ACB BAC BCA CAB CBA 
ABGS ABSG AGBS AGSB ASBG ASGB BAGS BASG BGAS BGSA BSAG BSGA GABS GASB GBAS GBSA GSAB GSBA SABG SAGB SBAG SBGA SGAB SGBA 

*/