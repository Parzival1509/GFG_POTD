// GFG POTD 2023/09/24
// Find Duplicates in an Array
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> duplicates(int arr[], int n) {
        vector<int> hsh(n, 0);
        for(int i = 0; i < n; i++)
            hsh[arr[i]]++;
        
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if(hsh[i] > 1) ans.push_back(i);
            
        if(ans.size() == 0) ans.push_back(-1);
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
4
0 3 1 2
5
2 3 1 2 3

Sample Output:
-1 
2 3 

*/