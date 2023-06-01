// GFG POTD 2023/05/20
// Hands of Straight
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) {
        if(groupSize == 1) return true;
        if(n % groupSize) return false;

        map<int, int> mp;
        for(int i: hand)
            mp[i]++;

        int grps = n/groupSize;
        for(int i = 0; i < grps; i++) {
            vector<int> tmp;
            int ct = groupSize;
            for(auto el: mp) {
                tmp.push_back(el.first);
                el.second--;
                ct--;
                if(ct == 0) break;
            }
            for(int j = 1; j < groupSize; j++)
                if(tmp[j] != tmp[j-1] + 1) return false;
        }
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;
        vector<int> hand(N);
        for(int i = 0; i < N; i++)
            cin >> hand[i];
        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if(ans) cout << "True" << endl;
        else cout << "False" << endl;
    }
    return 0;
}

/* Sample Input:
2
9 3
1 2 3 6 2 3 4 7 8
5 2
1 2 3 4 5

Sample Output:
True
False

*/