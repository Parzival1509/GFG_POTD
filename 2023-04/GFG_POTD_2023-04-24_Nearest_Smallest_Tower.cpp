// GFG POTD 2023/04/24
// Nearest Smallest Tower
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nearestSmallerTower(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> s1;

        // First find the nearest smallest element on the left
        for(int i = 0; i < n; i++) {
            while(s1.size() > 0 and arr[s1.top()] >= arr[i])
                s1.pop();
            if(s1.size() > 0) ans[i] = s1.top();
            s1.push(i);
        }
        while(s1.size()) s1.pop();
        
        // Now find the nearest smallest element on the right
        for(int i = n - 1; i >= 0; i--) {
            while(s1.size() > 0 and arr[s1.top()] >= arr[i])
                s1.pop();
            if(s1.size() > 0) {
                if(ans[i] == -1) ans[i] = s1.top();
                else {
                    if((i-ans[i]) > (s1.top()-i))
                        ans[i] = s1.top();
                    else if((i-ans[i]) == (s1.top()-i)){
                        if(arr[ans[i]] > arr[s1.top()])
                            ans[i] = s1.top();
                    }
                }
            }
            s1.push(i);
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}

/* Sample Input:
2
3
1 3 2
5
4 8 3 5 3

Sample Output:
-1 0 0 
2 2 -1 2 -1 

*/