// GFG POTD 2022/11/18
// Number of Open Doors
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int noOfOpenDoors(long long n) {
        return ceil(sqrt(n+1)-1);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.noOfOpenDoors(N) << endl;
    }
    return 0;
}

/* Sample Input
2
2 4

Sample Output
1
2

*/