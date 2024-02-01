// GFG POTD 2023/04/07
// Add Minimum Characters
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addMinChar(string str) {
        int n = str.size(), i = 0, j = n-1, ans = 0;
        while(i <= j) {
            if(str[i] == str[j]) {
                i++;
                j--;
            }
            else {
                ans++;
                i = 0;
                j = n-1-ans;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
}

/* Sample Input:
2
ABCD
ABA

Sample Output:
3
0

*/
