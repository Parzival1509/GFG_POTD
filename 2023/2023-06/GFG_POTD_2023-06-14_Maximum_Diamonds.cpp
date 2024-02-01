// GFG POTD 2023/06/14
// Maximum Diamonds
// Easy

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll maxDiamonds(int A[], int N, int K) {
        priority_queue<int> pq;
        for(int i = 0; i < N; i++)
            pq.push(A[i]);
        
        ll ans = 0;
        while(K--) {
            ll mx = pq.top();
            pq.pop();
            ans += mx;
            pq.push(mx/2);
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        int A[N];
        for(int i = 0; i < N; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.maxDiamonds(A, N, K) << endl;
    }
    return 0;
}

/* Sample Input:
2
5 3
2 1 7 4 2
3 2
7 1 2

Sample Output:
22
24 

*/