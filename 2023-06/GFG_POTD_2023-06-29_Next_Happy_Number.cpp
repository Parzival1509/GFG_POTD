// GFG POTD 2023/06/29
// Next Happy Number
// Hard

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool solve(int n) {
        if(n == 1 || n == 7) return true;
        if(n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9)
            return false;
            
        int sqSum = 0;
        while(n != 0) {
            int d = n % 10;
            sqSum += d * d;
            n /= 10;
        }
        return solve(sqSum);
    }

    int nextHappy(int N) {
        while(true) {
            N++;
            if(solve(N)) return N;
        }
        return 0;
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}

/* Sample Input:
4
3 8 9 10

Sample Output:
7
10
10
13

*/