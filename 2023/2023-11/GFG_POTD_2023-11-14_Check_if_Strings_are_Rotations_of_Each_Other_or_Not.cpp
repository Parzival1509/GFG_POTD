// GFG POTD 2023/11/14
// Check if Strings are Rotations of Each Other or Not
// Basic

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areRotations(string s1, string s2) {
        s1 += s1;
        return s1.find(s2) != -1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;
        if(ob.areRotations(s1, s2)) cout << "true ";
        else cout << "false ";
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
geeksforgeeks forgeeksgeeks
mightandmagic andmagicmigth

Sample Output:
true 
false 

*/