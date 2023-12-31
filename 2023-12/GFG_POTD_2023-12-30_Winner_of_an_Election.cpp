// GFG POTD 2023/12/30
// Winner of an Election
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> winner(string arr[],int n) {
        unordered_map<string, int> m;
        int mx = 0;
        for(int i = 0; i < n; i++) {
            m[arr[i]]++;
            mx = max(mx, m[arr[i]]);
        }
        
        vector<string> p;
        for(auto a: m)
            if(mx == a.second)
                p.push_back(a.first);
        
        sort(p.begin(), p.end());
        
        return {p[0], to_string(mx)};
    }
};

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string arr[n];
        for(int i =0 ; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr, n);        
        cout << result[0] << " " << result[1] << endl;
    }

    return 0;
}

/* Sample Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark

Sample Output:
john 4
andy 1

*/