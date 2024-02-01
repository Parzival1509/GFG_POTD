// GFG POTD 2023/04/08
// Make the Array Beautiful
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            if(ans.empty())
                ans.push_back(arr[i]);
            else if(arr[i] >= 0 && ans[ans.size()-1] < 0)
                ans.pop_back();
            else if(arr[i] < 0 && ans[ans.size() - 1] >= 0)
                ans.pop_back();
            else ans.push_back(arr[i]);
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
    }
}

/* Sample Input:
2
4
4 2 -2 1
4
2 -2 1 -1

Sample Output:
4 1 


*/
