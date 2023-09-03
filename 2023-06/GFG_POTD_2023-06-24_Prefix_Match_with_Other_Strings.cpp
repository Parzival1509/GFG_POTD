// GFG POTD 2023/06/24
// Prefix Match with Other Strings
// Medium

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int klengthpref(string arr[], int n, int k, string str) {
        map<string, int> mp;
        for(int i = 0; i < n; i++)
            if(k <= arr[i].size())
                mp[arr[i].substr(0, k)]++;
        
        if(k > str.size()) return mp[str];
        return mp[str.substr(0, k)];
    }
};

int main() { 
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string arr[n];
        for(int i = 0; i < n; i++) {
            string s;
            cin >> arr[i];
        }
        string str;
        cin >> str;
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
}

/* Sample Input:
3
6 3
abba abbb abbc abbd abaa abca
abbg
3 2
geeks geeksforgeeks forgeeks
geeks
3 10
xc sce lyhspnz
xc

Sample Output:
4
2
0

*/