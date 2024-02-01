// GFG POTD 2023/04/17
// Job Sequencing Problem
// Medium

#include<bits/stdc++.h>
using namespace std; 

struct Job { 
    int id;  // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> JobScheduling(Job arr[], int n) { 
        int m = 0;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i].dead, arr[i].profit});
            m = max(m, arr[i].dead);
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> ans(2, 0), vis(m+1, 0);
        for(int i = 0; i < n; i++) {
            bool f = false;
            int j = v[i].first;
            while(j > 0) {
                if(!vis[j]) {
                    f = true, vis[j] = 1;
                    break;
                }
                j--;
            } 
            if(f) {
                ans[0]++;
                ans[1] += v[i].second;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Job arr[n];
        for(int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0; 
}

/* Sample Input:
2
4
1 4 20
2 1 10
3 1 40
4 1 30
5
1 2 100
2 1 19
3 2 27
4 1 25
5 1 15

Sample Output:
2 60
2 127

*/