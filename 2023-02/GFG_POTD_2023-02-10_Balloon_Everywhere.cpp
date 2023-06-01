// GFG POTD 2023/02/10
// Balloon Everywhere
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxInstance(string s) {
        map<char, int> mp;
        for(auto el: s)
            mp[el]++;
        return min({mp['b'], mp['a'], mp['l'] / 2, mp['o'] / 2, mp['n']});
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}

/* Sample Input:
2
nlaebolko
loonbalxballpoon

Sample Output:
1
2

*/