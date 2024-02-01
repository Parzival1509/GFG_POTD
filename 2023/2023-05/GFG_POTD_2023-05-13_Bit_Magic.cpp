// GFG POTD 2023/05/13
// Bit Magic
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bitMagic(int n, vector<int> &arr) {
        int ans = 0;
        for(int i=0; i<n/2; i++)
            if(arr[i] != arr[n-1-i] && i != n-1-i)
                ans++;
        return ceil(ans*1.0/2);
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
        cout<<ob.bitMagic(n, arr)<<endl;
    }
}

/* Sample Input:
3
3
1 0 1
4
1 0 0 0
9
1 1 1 0 0 1 0 1 1

Sample Output:
0
1
1

*/