// GFG POTD 2023/11/30
// Shortest Path from 1 to n
// Easy

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int minimumStep(int n) {
        // Approach 1: Using Loop, S.C. = O(1)
        int ans = 0;
        while(n != 1) {
            ans++;
            n = (n % 3)? (n - 1): (n / 3);
        }
        
        return ans;
        
        // // Approach 2: Recursion, S.C. = O(log N) (Recursive Stack Space)
        // if(n == 1) return 0;
        
        // return (n % 3)?(1 + minimumStep(n - 1)): (1 + minimumStep(n / 3));
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }

    return 0; 
}

/* Sample Input:
2
9
4

Sample Output:
2
2

*/