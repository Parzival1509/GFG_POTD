// GFG POTD Minimum Characters to be Added at Front to Make String Palindrome

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChar(string s){
        int n=s.length();
        string rev(s);
        reverse(rev.begin(), rev.end());

        string new_str = s+"#"+rev;
        int new_len = new_str.length();
            
        vector<int> tmp(new_len+1, 0);
        for(int i=1; i<new_len; i++){
            int t=tmp[i-1];
            while(t>0 && new_str[i]!=new_str[t])
                t=tmp[t-1];
            if(new_str[i] == new_str[t])
                t++;
            tmp[i]=t;
        }
        return n-tmp[new_len-1];
    }
    }

    // O(N^2) Approach
    // bool checkPalindrome(string s, int n){
    //     // cout<<s<<' ';
    //     for(int i=0; i<n/2; i++){
    //         if(s[i] != s[n-1-i])
    //             return false;
    //     }
    //     return true;
    // }

    // int minChar(string str){
    //     int ans=0, flag=0, n=str.size();
    //     for(int i=0; i<n; i++){
    //         string st = str.substr(0, n-i);
    //         // cout<<st<<' ';
    //         if(checkPalindrome(st, st.size())){
    //             ans = i;
    //             flag=1;
    //             break;
    //         }
    //     }
    //     if(flag)
    //         return ans;
    //     else
    //         return str.size();
    // }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans<<endl;
    }
    return 0;
}

/* Sample Input
4
abc
abcba
aabbbaaa
aabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb

Sample Output
2
0
1
38

*/