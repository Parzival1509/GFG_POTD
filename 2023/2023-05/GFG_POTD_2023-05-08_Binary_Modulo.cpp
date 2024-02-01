// GFG POTD 2023/05/08
// Binary Modulo
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int modulo(string s, int m) {
        int ans = 0, temp = 1, i = s.size() - 1;
        while(i >= 0) {
            if(s[i--] == '1') ans = (ans + temp) % m;
            temp = (temp * 2) % m;
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s, m)<<endl;
    }
    return 0;
}

/* Sample Input:
2
101 2
1000 4

Sample Output:
1
0

*/