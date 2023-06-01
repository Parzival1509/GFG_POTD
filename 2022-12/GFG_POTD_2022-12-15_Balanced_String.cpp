// GFG POTD 2022/12/15
// Balanced String
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string BalancedString(int n) {
        string ans="", alp="abcdefghijklmnopqrstuvwxyz";
        int num=n;
        while(n>=26) {
            ans += alp;
            n -= 26;
        }
        if(n==0) return ans;

        // N is even
        if(n%2==0) {
            for(int i=0; i<n/2; i++)
                ans.push_back('a'+i);
            for(int i=26-n/2; i<26; i++)
                ans.push_back('a'+i);
        }

        // N is odd
        else {
            int tmp=num, sum=0;
            while(tmp!=0) {
                sum += tmp%10;
                tmp /= 10;
            }

            // Sum of digits of N is even
            if(sum%2 == 0) {
                for(int i=0; i<(n+1)/2; i++)
                    ans.push_back('a'+i);
                for(int i=26-(n-1)/2; i<26; i++)
                    ans.push_back('a'+i);
            }

            // Sum of digits of N is odd
            else {
                for(int i=0; i<(n-1)/2; i++)
                    ans.push_back('a'+i);
                for(int i=26-(n+1)/2; i<26; i++)
                    ans.push_back('a'+i);
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

/* Sample Input
7
5
13
14
21
22
28
57
Sample Output
abxyz
abcdefguvwxyz
abcdefgtuvwxyz
abcdefghijpqrstuvwxyz
abcdefghijkpqrstuvwxyz
abcdefghijklmnopqrstuvwxyzaz
abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcyz

*/