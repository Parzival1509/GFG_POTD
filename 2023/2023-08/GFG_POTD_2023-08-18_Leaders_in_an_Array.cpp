// GFG POTD 2023/08/18
// Leaders in an Array
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    vector<int> leaders(int a[], int n) {
        vector<int> ans;
        int m = -1;

        for(int i = n - 1; i >= 0; i--)
            if(a[i] >= m) {
                m = a[i];
                ans.push_back(m);
            }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
   ll t;
   cin >> t;
   while(t--) {
        ll n;
        cin >> n;
        int a[n];
        for(ll i = 0; i < n; i++)
            cin >> a[i];

        Solution obj;
        vector<int> v = obj.leaders(a, n);
        for(auto it = v.begin(); it != v.end(); it++)
            cout << *it << " ";
        cout << endl;

   }
}

/* Sample Input:
2
6
16 17 4 3 5 2
5
1 2 3 4 0

Sample Output:
17 5 2
4 0

*/