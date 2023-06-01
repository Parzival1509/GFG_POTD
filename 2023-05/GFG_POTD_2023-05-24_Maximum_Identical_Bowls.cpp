// GFG POTD 2023/05/24
// Maximum Identical Bowls
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximum(int n, vector<int> &arr) {
        long long sum = accumulate(arr.begin(), arr.end(), 1LL*0);
        int i = n;
        for(; i > 0; i--)
            if(sum % i == 0) break;
        
        return i;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n, 0);
        for(int &i: arr)
            cin>>i;
        Solution ob;
        cout<<ob.getMaximum(n, arr)<<endl;
    }
}

/* Sample Input:
2
3
3 1 5
4
1 2 6 5

Sample Output:
3
2

*/