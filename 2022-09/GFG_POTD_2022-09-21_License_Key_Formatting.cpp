// GFG POTD License Key Formatting
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string ReFormatString(string S, int K){
        vector<char> str;
        int ct = 0;
        for(int i=0;i<S.size();++i){
            if(S[i] != '-'){
                if(S[i] >= 97 && S[i] <= 122){
                    S[i] = S[i] - 32;
                }
                str.push_back(S[i]);
                ct++;
            }
        }
        string s = "";
        if(ct%K){
            for(int i=0;i<ct%K;++i){
                s+=str[i];
            }
            if(ct%K < str.size()){
                s+='-';
            }
        }
            int cnt = 0;
            for(int i=ct%K;i<str.size();++i){
                if(cnt == K){
                    cnt = 0;
                    s+='-';
                }
                s+=str[i];
                cnt++;
            }
        return s;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        int K;
        cin >> K;
        Solution ob;  
        string ans=ob.ReFormatString(S, K);
        cout<<ans;
        cout<<"\n";
    }
    return 0;
}

/* Sample Input2
2
5F3Z-2e-9-w
4
ab3-sdf-de
2

Sample Output
5F3Z-2E9W
AB-3S-DF-DE

*/