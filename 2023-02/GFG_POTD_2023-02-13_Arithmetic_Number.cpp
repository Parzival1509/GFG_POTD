// GFG POTD 2023/02/13
// Arithmetic Number
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int inSequence(int a, int b, int c) {
        if(c==0) return a==b;
        if(c>0 && b>=a && (b-a)%c==0) return 1;
        if(c<0 && b<=a && (b-a)%c==0) return 1;
        return 0;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int A, B, C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}

/* Sample Input:
4
1 2 3
1 3 2
4 -12 4
10 10 0

Sample Output:
0
1
0
1

*/