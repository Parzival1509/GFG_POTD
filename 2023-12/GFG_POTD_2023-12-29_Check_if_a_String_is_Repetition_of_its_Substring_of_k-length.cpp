// GFG POTD 2023/12/29
// Check if a string is repetition of its substring of k-length
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kSubstrConcat(int n, string s, int k) {
        if(n % k == 0) {
            unordered_map<string, int> mp;
            string str = "", str1 = "", temp = "";
            
            for(int i = 0; i < n;) {
                temp = "";
                while(i < n && temp.size() < k) {
                   temp.push_back(s[i]);
                   i++;
                }
                
                if(str == "") str = temp;
                else if(str1 == "" && temp != str) str1 = temp;
                mp[temp]++;
            }
            
            if(mp.size() == 2) {
                auto it = mp.begin();
                auto it1 = it;
                it1++;
                if((it)->second != 1 && (it1)->second != 1)
                    return 0;
                return 1;
            }
            
            if(mp.size() == 1)
                return 1;
            return 0;
        }
        
        return 0;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        int n, k;
        cin >> n >> s >> k;
        Solution  ob;
        cout << ob.kSubstrConcat (n, s, k) << endl;
    }
}

/* Sample Input:
2
4 bdac 2
5 abcde 2

Sample Output:
1
0

*/