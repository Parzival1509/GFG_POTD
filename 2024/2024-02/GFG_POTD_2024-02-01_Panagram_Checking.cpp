// GFG POTD 2024/02/01
// Panagram Checking
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPangram (string s) {
        int temp = 0;
        
        for(auto& c: s) {
            char ch = tolower(c);
            if(ch >= 'a' && ch <= 'z')
                temp |= (1 << ch-'a');
        }
        
        return temp == 67108863;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while(t--) {
        string s;
        getline(cin, s);
        Solution obj;
        if(obj.checkPangram(s) == true)
            cout << 1 << endl;
        else cout << 0 << endl;
    }

    return(0);
}

/* Sample Input:
2
Bawds jog, flick quartz, vex nymph
sdfs

Sample Output:
1
0

*/