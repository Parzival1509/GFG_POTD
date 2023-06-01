//GFG POTD Generate IP Adresses
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void sol(vector<string>& v , std::vector<string>& ans , string& s,int i)
    {
        if(i == s.size() and v.size() == 4)
        {
            string temp ;
            for(auto el:v)
            {
                temp.append(el) ;
                temp.push_back('.') ;
            }

            temp.pop_back() ;    
            ans.push_back(temp) ;
            return ;
        }

        if(i >= s.size()) 
            return ;
           
        if(v.size() < 4)
        {
            string temp ;
            temp.push_back(s[i]) ;
            v.push_back(temp);
            sol(v,ans,s,i+1);
            v.pop_back();       
        }

        if(s[i] != '0' and i+1 < s.size() and v.size() < 4)
        {
            string temp ;
            temp.push_back(s[i]) ;
            temp.push_back(s[i+1]) ;
            v.push_back(temp) ;
            sol(v,ans,s,i+2);
            v.pop_back();
        }
        if(s[i] != '0' and i+2<s.size() and v.size() < 4)
        {
            int a = (s[i]-'0')*100 ;
            int b = (s[i+1]-'0')*10 ;
            int c = (s[i+2]-'0') ;
            if(a+b+c <= 255)
            {
                string temp ;
                temp.push_back(s[i]) ;
                temp.push_back(s[i+1]) ;
                temp.push_back(s[i+2]) ;
                v.push_back(temp) ;
                sol(v,ans,s,i+3);
                v.pop_back() ;
            } 
        }
    }

    vector<string> genIp(string &s) {
        std::vector<string> ans;
        vector<string> a ;
        sol(a,ans,s,0) ;
        return ans ;    
    }

};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /generating naively/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}

/* Sample Input

Sample Output

*/