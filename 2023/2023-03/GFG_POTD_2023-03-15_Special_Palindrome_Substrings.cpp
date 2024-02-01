// GFG POTD 2023/03/15
// Special Palindrome Substrings
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string s, int ind, int m, int i, int j) {
        int change = 0;
        while(i < j) {
            if(s[i] != s[j]) {
                if(i >= ind and j <= (ind + m - 1))
                    return 1e9;
                change++;
            }
            i++;
            j--;
        }
        return change;
    }
    
    int specialPalindrome(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        string temp = s1;
        int mini = 1e9;
        for(int i = 0; i <= n - m; i++) {
            int op = 0;
            for(int j = 0; j < m; j++) {
                if(temp[i + j] != s2[j]) op++;
                temp[i + j] = s2[j];
            }
            mini = min(mini, op + solve(temp, i, m, 0, n - 1));
            temp = s1;
        }
        return mini == 1e9? -1: mini;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--) {
        string s1, s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1, s2);
        cout<<ans<<endl;
    }
}

/* Sample Input:
2
abaa bb
abbd mr

Sample Output:
1
4

*/