// GFG POTD 2023/08/09
// Largest Prime Factor
// Medium

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int largestPrimeFactor(int n) {
        int ans = 1, i = 2;;
        while(n > 1) {
            if(n % i == 0) ans = i;
            while(n % i == 0)
                n /= i;
            i++;
        }
        
        return ans;
    }
};

int main() { 
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}

/* Sample Input:
2
5 24

Sample Output:
5
3

*/