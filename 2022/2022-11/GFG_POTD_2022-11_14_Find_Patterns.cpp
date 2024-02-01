// GFG POTD 2022/11/14
// Find Patterns

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int numberOfSubsequences(string s, string w){
        int k, ans=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]==w[0]) {
                k=0;
                for(int j=0; j<s.size() && k<w.size(); j++) {
                    if(s[j]==w[k]) {
                        s[j]='@';
                        k++;
                    }
                }
                if(k==w.size())
                    ans++;
            }
        }
        return ans;
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 

/* Sample Input
2
abcdrtbwerrcokokokd bcd
ascfret qwer

Sample Output
2
0

*/