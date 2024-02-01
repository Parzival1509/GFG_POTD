// GFG POTD 2022/12/17
// Break a Number
// Easy

#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    int waysToBreakNumber(int n){
        long m=1e9+7;
        return (((n+1)%m * (n+2)%m)%m)/2;
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
}

/* Sample Input
6
1 2 3 4 5 1000055

Sample Output
3
6
10
15
21
-307188388 // Compiler Issue

*/