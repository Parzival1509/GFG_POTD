// GFG POTD 2023/08/24
// Multiply Two Strings
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiplyStrings(string s1, string s2) {
        if(s1 == "0" || s2 == "0") return "0";
        
        int neg = 1;
        // Checking for negative signs
        if(s1[0] == '-') {
            s1 = s1.substr(1);
            neg *= -1;
        }

        if(s2[0] == '-') {
            s2 = s2.substr(1);
            neg *= -1;
        }
        
        int n1 = s1.size(), n2 = s2.size();
        string ans(n1 + n2, '0');
        
        for(int i = n2 - 1; i >= 0; i--) {
            int carry = 0;
            // Multiplying s2 with each digit
            for(int j = n1 - 1; j >= 0; j--) {
                int pdt = (s1[j] - '0') * (s2[i] - '0') + (ans[i + j + 1] - '0') + carry;
                carry = pdt / 10;
                ans[i + j + 1] = (pdt % 10) + '0';
            }
            ans[i] += carry;
        }
        
        int start = 0;
        while(start < ans.size() - 1 && ans[start] == '0')
            start++;
        ans = ans.substr(start);
        
        if(neg == -1 && ans != "0")
            ans = "-" + ans;

        return ans;
    }
};
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }
     
}

/* Sample Input:
5
0033 2
11 23
986 -24
986 24
95 95

Sample Output:
66
253
-23664
23664
9025

*/