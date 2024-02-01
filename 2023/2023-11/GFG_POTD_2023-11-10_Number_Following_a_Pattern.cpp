// GFG POTD 2023/11/10
// Number Following a Pattern
// Medium

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    string printMinNumberForPattern(string s) {
        string ans = "";
        for(int i = 1; i <= s.size() + 1; i++)
            ans += '0' + i;
        
        while(true) {
            int j = 1, k = 0;
            bool f = true;
            
            while(j < ans.size()) {
                if(s[k] == 'D' && ans[j] > ans[j - 1]) {
                    swap(ans[j], ans[j - 1]);
                    f = false;
                }
              
                if(s[k] == 'I' && ans[j] < ans[j - 1]) {
                    swap(ans[j], ans[j - 1]);
                    f = false;
                }
                
                j++;
                k++;
            }
            
            if(f == true) break;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }

    return 0; 
} 

/* Sample Input:
2
D
IIDDD

Sample Output:
21
126543

*/