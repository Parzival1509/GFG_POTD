// GFG POTD 2023/05/03
// Make Palindrome
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makePalindrome(int n, vector<string> &arr) {
        map<string, int> mp;
        for(auto it: arr) mp[it]++;
        
        int odd = 0;
        for(auto i: mp) {
            string temp = i.first;
            reverse(temp.begin(), temp.end());
            
            if(i.first == temp) {
                if(i.second % 2) odd++;
                if(odd > 1) return false;
            }
            else if(i.second != mp[temp]) return false;
        }
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        if(ob.makePalindrome(n, arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

/* Sample Input:
3
3
ghdas adsda sadhg
3
jhjdf sftas fgsdf
4
djfh gadt hfjd tdag

Sample Output:
YES
NO
YES

*/