// GFG POTD 2022/11/16
// Sum of Beauty of All Substrings

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n=s.size(), sum=0;
        for(int i=0; i<n; i++) {
            unordered_map<char, int> mp;
            for(int j=i; j<n; j++) {
                mp[s[j]]++;
                int mn=INT_MAX, mx=INT_MIN;
                for(auto el: mp) {
                    if(el.second>mx)
                        mx=el.second;
                    if(el.second<mn)
                        mn=el.second;
                }
                sum += mx-mn;
            }
        }
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}

/* Sample Input
2
aaac
geeksforgeeks

Sample Output
3
62

*/