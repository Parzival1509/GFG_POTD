// GFG POTD 2023/06/15
// Longest Palindrome in a String
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalin (string S) {
        int start = 0, end = 0;
        int low, high;
        for(int i = 0; i < S.length(); i++) {
            // Odd part
            low = i - 1;
            high = i;
            while(low >= 0 && high < S.length() && S[low] == S[high]) {
                if(high - low + 1 > end) {
                    end = high - low + 1; //current longest pallindrome length
                    start = low;
                }
                low--;
                high++;
            }
            
            // Even part
            low = i - 1;
            high = i + 1;
            while(low >= 0 && high < S.length() && S[low] == S[high]) {
                if(high - low + 1 > end) {
                    end = high - low + 1; //current longest pallindrome length
                    start = low;
                }
                low--;
                high++;
            }
        
        }
        
        if(end == 0)
            return S.substr(start, 1);
        return S.substr(start, end);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}

/* Sample Input:
2
aaaabbaa
abc

Sample Output:
aabbaa
a

*/