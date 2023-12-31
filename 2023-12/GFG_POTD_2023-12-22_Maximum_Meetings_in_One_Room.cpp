// GFG POTD 2023/12/22
// Maximum Meetings in One Room
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f) {
        vector<pair<pair<int, int>, int>> pr;
        for(int i = 0; i < n; i++)
            pr.push_back({{f[i], s[i]}, i + 1});

        sort(pr.begin(), pr.end());

        vector<int> ans;
        ans.push_back(pr[0].second);
        int fTime = pr[0].first.first;

        for(int i = 1; i < n; i++)
            if(pr[i].first.second > fTime) {
                ans.push_back(pr[i].second);
                fTime = pr[i].first.first;
            }

        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> S(n), F(n);
        for(int i = 0; i < n; i++)
            cin >> S[i];
        for(int i = 0; i< n; i++)
            cin >> F[i];
        Solution ob;
        vector<int> ans = ob.maxMeetings(n, S, F);
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if(i != ans.size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}

/* Sample Input:
2
6
1 3 0 5 8 5
2 4 6 7 9 9
1
3
7

Sample Output:
1 2 4 5
1

*/