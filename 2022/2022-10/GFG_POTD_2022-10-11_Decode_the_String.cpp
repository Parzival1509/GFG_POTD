// GFG POTD Decode the String

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string decodedString(string code){
        long long n=code.size(), val, num=0;
        stack<long long> ct;
        stack<string> s;
        char ch;
        string st="", tmp="";

        for(int i=0; i<n; i++){
            ch=code[i];
            // if(tmp!="")
            //     cout<<tmp<<' ';
            // else
            //     cout<<1<<' ';
            if(ch!='[' && ch!=']'){
                val=ch-'0';
                if(val<0 || val>9){
                    tmp += ch;
                }
                else{
                    num = num*10 + val;
                }
            }
            else if(ch=='['){
                s.push(tmp);
                tmp = "";
                ct.push(num);
                num = 0;
            }
            else{
                for(int i=0; i<ct.top(); i++){
                    st += tmp;
                }
                // cout<<tmp<<' ';
                tmp = st;
                st = "";
                ct.pop();
                if(!s.empty()){
                    tmp = s.top()+tmp;
                    s.pop();
                }
            }
        }
        return tmp;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        Solution ob;
        // cout<<endl;
        cout<<ob.decodedString(s)<<"\n";
        // cout<<endl;
    }
    return 0;
}

/* Sample Input
3
1[b]
3[b2[ca]]
cab2[c2[de]ab]

Sample Output
b
bcacabcacabcaca
cabcdedeabcdedeab

*/