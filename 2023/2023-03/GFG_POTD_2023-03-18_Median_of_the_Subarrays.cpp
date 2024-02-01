// GFG POTD 2023/03/18
// Median of the Subarrays
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long solve(vector<int>& A, int N, int M) {
        unordered_map<int, int> map;
        int cur = 0;
        long tot = 0, ans = 0;
        map[cur] = 1;

        for(int i = 0; i < N; i++) {
            int x;
            if(A[i] >= M) x = 1;
            else x = -1;

            if (x == -1) tot -= map[cur - 1];
            else tot += map[cur];

            cur += x;
            ans += tot;
            map[cur] = map[cur] + 1;
        }
        return ans;
    }

    long countSubarray(int N, vector<int>& A, int M) {
        return solve(A, N, M) - solve(A, N, M + 1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution obj;
        auto ans = obj.countSubarray(N, A, M);
        cout<<ans<<endl;
    }
}

/* Sample Input:
2
5 2
2 1 3 5 4
1 1
1

Sample Output:
3
1

*/