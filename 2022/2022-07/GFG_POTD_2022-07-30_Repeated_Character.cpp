#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    char firstRep (string s)
    {
        int hsh[26];
        memset(hsh, 0, sizeof hsh);
        for(int i=0; i<s.size(); i++){
            hsh[s[i]-'a']++;
        }
        for(auto el: s){
            if(hsh[el-'a'] > 1)
                return el;
        }
        return '#';
        
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}