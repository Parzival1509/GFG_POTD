// GFG POTD 2023/06/16
// Min Time
// Medium

#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
    
class Solution {
public:
    ll minTime(int n, vector<int> &locations, vector<int> &types) {
        int mx = *max_element(begin(types), end(types));
        vector<pair<int, int>> ar(mx + 1, {INT_MAX, INT_MIN});
        ar[0].first = 0, ar[0].second = 0;
        for(int i = 0; i < n; i++) {
            ar[types[i]].first = min(locations[i], ar[types[i]].first);
            ar[types[i]].second = max(locations[i], ar[types[i]].second);
        }
        
        vector<vector<ll>> arr;
        for(int i = 0; i <= mx; i++) {
            if(ar[i].first == INT_MAX)
                continue;
            else arr.push_back({i , ar[i].first , ar[i].second});
        }
        
        vector<ll> next(3, 0), curr(3, 0);
        next[1] = abs(arr[arr.size() - 1][1]);
        next[2] = abs(arr[arr.size() - 1][2]);
        
        for(int i = arr.size() - 1; i >= 0; i--) {
            for(int choose = 1; choose <= 2; choose++) {
                ll op1 = LLONG_MAX, op2 = LLONG_MAX;
                if(i == 0) op1 = min(op1, next[choose]);
                else {
                    if(arr[i][1] <= arr[i - 1][choose] && arr[i][2] >= arr[i - 1][choose]) {
                        // If choose to go right first then go left
                        ll distance = abs(arr[i - 1][choose] - arr[i][2]) + abs(arr[i][2] - arr[i][1]);
                        op1 = min(op1, distance + next[1]);
                        distance = abs(arr[i - 1][choose] - arr[i][1]) + abs(arr[i][2] - arr[i][1]);
                        op2 = min(op2, distance + next[2]);
                    }
                    else {
                        // Both min and max are at same sides
                        if(arr[i][1] <= arr[i - 1][choose] && arr[i][1] <= arr[i][2])
                            op1 = min(op1, abs(arr[i - 1][choose] - arr[i][1]) + next[1]);
                        else
                            op1 = min(op1, abs(arr[i - 1][choose] - arr[i][2]) + next[2]);
                    }
                }
                curr[choose] = min(op1, op2);
            }
            swap(curr, next);
        }
        
        return next[2];
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> locations(n);
        for(int i = 0; i < n; i++)
            cin >> locations[i];
        vector<int> types(n);
        for(int i = 0; i < n; i++)
            cin >> types[i];
        Solution obj;
        ll res = obj.minTime(n, locations, types);
        cout << res << endl;
    }
}

/* Sample Input:
2
4
1 3 5 7
1 2 3 1
4
-4 -3 1 -8
4 2 4 5

Sample Output:
18
24

*/