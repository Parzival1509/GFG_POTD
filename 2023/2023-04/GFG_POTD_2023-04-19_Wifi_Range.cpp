// GFG POTD 2023/04/19
// Wifi Range
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wifiRange(int n, string s, int x) {
        // Approach 1
        int pending = 0, relax = 0;
        for(auto &ch: s) {
            if(ch == '1') {
                pending = 0;
                relax = x;
            }
            else {
                if(relax) relax--;
                else if(pending == x) return false;
                else pending++;
            }
        }
        return pending? false: true;
        
        // // Approach 2
        // int lastEnd = 0;
        // for(int i = 0; i < n; i++) {
        //     if(s[i] == '1') {
        //         if(i-x > lastEnd) return 0;
        //         lastEnd = i+x+1;
        //     }
        // }
        // return lastEnd >= n;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, x;
        string s;
        cin >> n >> x >> s;
        Solution obj;
        if(obj.wifiRange(n, s, x)) cout<<"true ";
        else cout<<"false ";
        cout<<endl;
    }
}

/* Sample Input:
3
3 0
010
5 1
10010
8 3
10000001

Sample Output:
false 
true 
true 

*/