// GFG POTD 2023/04/04
// Minimum Steps Required
// Medium

#include <bits/stdc++.h>
using namespace std;

int minSteps(string str) {
    int ct = 1;
    for(int i = 1 ; i < str.size(); i++)
        if(str[i] != str[0]) {
            ct++;
            while(i < str.size() && str[i] != str[0]) i++;
        }
    
    return ct;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

/* Sample Input:
2
bbaaabb
aababaa

Sample Output:
2
3

*/