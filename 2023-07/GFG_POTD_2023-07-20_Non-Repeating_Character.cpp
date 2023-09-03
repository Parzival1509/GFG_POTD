// GFG POTD 2023/07/20
// Non-Repeating Character
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char nonrepeatingCharacter(string s) {
        unordered_map<char, int> hsh;
        for(char ch: s)
            hsh[ch]++;
        
        char ans = '$';
        for(char ch: s)
            if(hsh[ch] == 1) {
                ans = ch;
                break;
            }
            
        return ans;
    }
};

int main() {
    int T;
    cin >> T;
    while(T--){
        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$') cout << ans;
        else cout << "-1";    
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
hello zxvczbtxyzvy

Sample Output:
h
c

*/