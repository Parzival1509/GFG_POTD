// GFG POTD 2022/11/23
// Maximum Sum LCM

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int maxSumLCM(int n) {
        long long int ans = 0;
        for(int i=1;i*i<=n;i++)
            if(n%i == 0){
                ans += i;
                if(i != n/i)
                    ans += n/i;
            }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n ;
        Solution ob;
        cout<<ob.maxSumLCM(n)<<endl;
    }
    return 0;
}


/* Sample Input
2
2
5

Sample Output
3
6

*/