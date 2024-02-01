// GFG POTD 2023/01/22
// GCD Array
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int> &arr) {
        // Prefix Sum
        int sum = 0;
        vector<int> pre(n, 0);
        for(int i=0; i<n; i++) {
            sum += arr[i];
            pre[i] = sum;
        }

        // Divisors of the Sum
        vector<int> divisors;
        for(int i=1; i*i<=sum; i++) {
            if(sum%i == 0) {
                divisors.push_back(i);
                if(i != sum/i)
                    divisors.push_back(sum/i);
            }
        }

        // Finding the GCD
        int ans = 1;
        for(auto div: divisors) {
            int tmp = k;
            for(auto el: pre)
                if(el%div == 0) tmp--;
            if(tmp <= 0)
                ans = max(ans, div);
        }
        return ans;
    }
};

int main(){
    int T;
    cin>>T;
    Solution ob;
    while(T--) {
        int n, k;
        cin>>n>>k;
        vector<int> arr(n);
        for(auto &i: arr)
            cin>>i;
        cout<<ob.solve(n, k, arr)<<endl;
    }
}

/* Sample Input
2
5 4
6 7 5 27 3
3 2
1 4 5

Sample Output
3
6

*/