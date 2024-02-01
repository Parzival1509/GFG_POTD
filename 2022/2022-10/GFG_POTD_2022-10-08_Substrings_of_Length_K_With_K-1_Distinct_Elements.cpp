// GFG POTD Substrings of Length K with K-1 Distinct Elements

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOfSubstrings(string st, int k) {
        int i=0, j=0, n=st.size(), ct=0;
        unordered_map<char, int> mp;
        while(i<n){
            mp[st[i]]++;
            if(i-j+1<k){
                i++;
            }
            else if(i-j+1==k){
                if(mp.size()==k-1){
                    cout<<st.substr(j, i-j+1)<<' ';
                    ct++;
                }
                mp[st[j]]--;
                if(mp[st[j]]==0)
                    mp.erase(st[j]);
                i++;
                j++;
            }
        }
        return ct;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}

/* Sample Input
2
abcc 2
aabab 3

Sample Output
cc 1
aab aba bab 3

*/