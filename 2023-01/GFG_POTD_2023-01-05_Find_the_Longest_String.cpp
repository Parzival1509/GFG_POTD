// GFG POTD 2023/01/05
// Find the Longest String
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestString(vector<string> &words) {
        sort(words.begin(), words.end());
        unordered_map<string, int> mp;
        for(auto el: words)
        	mp[el]++;

        string ans = "";
        for(int i=words.size()-1; i>=0; i--) {
        	string word = words[i];
        	bool f = true;
        	for(int j=0; j<word.size(); j++) {
        		string tmp = word.substr(0, j+1);
        		if(mp.find(tmp) == mp.end()) {
        			f = false;
        			break;
        		}
        	}
        	if(f && ans.size()<word.size())
        		ans = word;
        	else if(f && ans.size()==word.size())
        		ans = min(ans, word);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

/* Sample Input
2
4
ab a abc abd
9
ab a aa abd abc abdd abde abda abdab

Sample Output
abc
abdab

*/