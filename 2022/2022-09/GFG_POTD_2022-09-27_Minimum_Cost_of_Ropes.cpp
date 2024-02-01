// GFG POTD Minimum Cost of Ropes

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        long long ans = 0;
        long long sum = 0;
        while(pq.size()>1){
            sum += pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
            pq.push(sum);
            ans += sum;
            sum = 0;
        }
        return ans;
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

/* Sample Input
2
4
4 3 2 6
5
4 2 7 6 9

Sample Output
29
62

*/