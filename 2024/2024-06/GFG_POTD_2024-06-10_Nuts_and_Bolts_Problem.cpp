// GFG POTD 2024/06/10
// Nuts and Bolts Problem
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void matchPairs(int n, char nuts[], char bolts[]) {
        sort(nuts, nuts + n);
        sort(bolts, bolts + n);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++)
            cin >> nuts[i];
        for (int i = 0; i < n; i++)
            cin >> bolts[i];
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++)
            cout << nuts[i] << " ";
        cout << "\n";
        for (int i = 0; i < n; i++)
            cout << bolts[i] << " ";
        cout << "\n";
    }
    return 0;
}

/* Sample Input
2
5
@ % $ # ^
% @ # $ ^
9
^ & % @ # * $ ? !
? # @ % & * $ ^ !

Sample Output
# $ % @ ^ 
# $ % @ ^ 
! # $ % & * ? @ ^ 
! # $ % & * ? @ ^ 

*/