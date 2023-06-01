// GFG POTD 2022/09/10
// Ball Coloring
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    unsigned long long int noOfWays(unsigned long long int n){
        return n*(n-1)+2;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        unsigned long long int n;
        cin >> n;
        Solution ob;
        cout<<ob.noOfWays(n)<<endl;
    }
    return 0;
}

/* Sample Input
2
1
2

Sample Output
2
4

*/