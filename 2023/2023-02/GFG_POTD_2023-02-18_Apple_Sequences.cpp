// GFG POTD 2023/02/18
// Apple Sequences
// Easy

#include<bits/stdc++.h> 
using namespace std; 

class Solution {   
public:
    int appleSequences(int n, int m, string s) {
        int i = 0, j = 0, ct = 0, res = 0;
        while(j < n) {
            if(s[j] == 'O') {
                if(m > 0) m--;
                else {
                    while(s[i] != 'O') i++;
                    i++;
                }
            }
            // cout<<i<<' '<<j<<endl;
            res = max(res, j-i+1);
            j++;
        }

        // for(int i=0, j=0; i<s.size(); i++) {
        //     ct += s[i]=='O';
        //     while(ct > m) ct -= s[j++]=='O';
        //     res = max(res, i-j+1);
        // }
        return res;
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        string arr;
        cin >> arr;
        Solution ob;
        cout << ob.appleSequences(N, M, arr) << endl;
    }
    return 0; 
}

/* Sample Input:
2
5 1 AAOAO
5 1 AOOAO

Sample Output:
2
4

*/