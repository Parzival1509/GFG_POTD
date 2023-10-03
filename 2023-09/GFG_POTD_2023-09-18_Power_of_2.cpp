// GFG POTD 2023/09/18
// Power of 2
// Basic

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerofTwo(long long n) {
        float m = (log(n) / log(2));
        return (m == int(m))? true: false;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        long long n;
        cin >> n;
        Solution ob;
        if(ob.isPowerofTwo(n)) cout<<"YES ";
        else cout<<"NO ";
        cout<<endl;
    }

    return 0;
}

/* Sample Input:
5
1
4
10
98
1024

Sample Output:
YES 
YES 
NO 
NO 
YES 

*/