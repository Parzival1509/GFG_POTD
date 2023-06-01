// GFG POTD 2023/04/16
// Unequal Arrays
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll solve(int N, vector<int> &A, vector<int> &B) {
        vector<int> AEvenOdd[2], BEvenOdd[2];
        ll sum1 = 0, sum2 = 0;
        
        for(int i = 0; i < N; ++i) {
            sum1 += A[i];
            sum2 += B[i];
            
            if(abs(A[i]) % 2 == 0) AEvenOdd[0].push_back(A[i]);
            else AEvenOdd[1].push_back(A[i]);
                
            if(abs(B[i]) % 2 == 0) BEvenOdd[0].push_back(B[i]);
            else BEvenOdd[1].push_back(B[i]);
        }
        
        if(sum1 != sum2 || (AEvenOdd[0].size() != BEvenOdd[0].size()))
            return -1;
        
        ll ans = 0;
        for(int i = 0; i < 2; ++i) {
            sort(AEvenOdd[i].begin(), AEvenOdd[i].end());
            sort(BEvenOdd[i].begin(), BEvenOdd[i].end());
            
            for(int j = 0; j < AEvenOdd[i].size(); ++j)
                ans += abs(AEvenOdd[i][j] - BEvenOdd[i][j]) / 2;
        }
        return ans / 2;
    }
};

int main() {
    int T;
    cin >> T;
    Solution ob;
    while (T--) {
        int n;
        cin>>n;
        vector<int> a(n, 0), b(n, 0);
        for(auto &i: a)
            cin>>i;
        for(auto &i: b)
            cin>>i;
        cout<<ob.solve(n, a, b)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
2 5 6
1 2 10
2
3 3
9 8

Sample Output:
2
-1

*/