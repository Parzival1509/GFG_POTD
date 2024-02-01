// GFG POTD 2022/10/24
// Earthquake and the Paint Shop
// Easy

#include <bits/stdc++.h>
using namespace std;

struct alphanumeric {
    string name;
    int count;
};

class Solution {
public:
    vector<alphanumeric> sortedStrings(int n, vector<string> a) {
        vector<alphanumeric> ans;
        map<string, int> mp;
        for(auto el: a)
            mp[el]++;
        for(auto el: mp)
            ans.push_back({el.first, el.second});
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u: ans)
            cout << u.name << " " << u.count << endl;
        cout<<endl;
    }
}

/* Sample Input
2
2
3122049353 onafrnbhtr 9822827304 yzfhdgzcvx 
2992299540 lpvkgykmlk 6946169466 vdqwvywwgg
3
2234597891 zmxvvxbcij 8800654113 jihgfedcba
1234567891 abcdefghij 9876543219 jihgfedcba
2234597891 zmxvvxbcij 8800654113 jihgfedcba

Sample Output
2992299540 lpvkgykmlk 6946169466 vdqwvywwgg 1
3122049353 onafrnbhtr 9822827304 yzfhdgzcvx  1

1234567891 abcdefghij 9876543219 jihgfedcba 1
2234597891 zmxvvxbcij 8800654113 jihgfedcba 2


*/