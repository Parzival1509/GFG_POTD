// GFG POTD 2023/04/06
// Equal Left and Right Subarray Sum
// Easy

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int equalSum(int n, vector<int> &a) {
        if(n == 1) return 1;
        
        int left = 0;
        int sum = accumulate(a.begin(), a.end(), 0);
        for(int i=0; i<n; i++) {
            sum -= a[i];
            if(left == sum) return i+1;
            left += a[i];
        }
        return -1;
    }
};

int main() {
    Solution ob;
    int T = 1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int &i: a)
            cin>>i;
        cout<<ob.equalSum(n, a)<<endl;
    }
    return 0;
}

/* Sample Input:
2
5
1 3 5 2 2
1
1

Sample Output:
3
1

*/
