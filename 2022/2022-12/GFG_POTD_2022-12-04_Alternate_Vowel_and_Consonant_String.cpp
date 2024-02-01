// GFG POTD 2022/12/04
// Alternate Vowel and Consonant String
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    string rearrange (string s, int N) {
        int vow[26]={0}, cons[26]={0};
        for(int i=0; i<N; i++)
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                vow[s[i]-'a']++;
            else
                cons[s[i]-'a']++;
        
        int dif = 0;
        for(int i=0; i<26; i++)
            dif += vow[i]-cons[i];
        if(dif<-1 || dif>1)
            return "-1";

        int idx=0, idx2=0;
        bool b=0;
        if(dif==-1) b=1;
        for(int i=0; i<N; i++)
            if(i&1^b){
                while(cons[idx2]==0) idx2++;
                s[i] = 'a'+idx2;
                cons[idx2]--;
            }
            else{
                while(vow[idx]==0) idx++;
                s[i] = 'a'+idx;
                vow[idx]--;
            }
        return s;
    }
};

int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        cout << ob.rearrange (s, n) << endl;
    }
}

/* Sample Input
2
9 aeroplane
11 mississippi

Sample Output
alanepero
-1

*/