// GFG POTD 2024/01/06
// Techfest and the Queue
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if(n == 2 || n == 3) return true;
        if(n % 2 == 0 || n % 3 == 0)
            return false;
        
        for(int i = 5; i * i < n; i += 6)
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
        
        return true;
    }
    
    int prime_pow_sum(int n, vector<int> prm) {
        int su = 0;
        for(auto it: prm) {
            if((it > n) || n == 1)
                break;
            while(n % it == 0) {
                su++;
                n /= it;
            }
        }
        
        if(n != 1) su++;
        
        return su;
    }
    
    int sumOfPowers(int a, int b) {
        int ans = 0, p = sqrt(b);
        vector<int> prm;
        for(int i = 2; i <= p; i++)
            if(isPrime(i))
                prm.push_back(i);
        
        for(int i = a; i <= b; i++) {
            int temp = prime_pow_sum(i, prm);
            ans += temp;
        }
        
        return ans;
    }
};

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int a, b;
        cin >> a >> b;
        Solution obj;
        int ans = obj.sumOfPowers(a, b);
        cout << ans << "\n";
    }

    return 0;
}

/* Sample Input:
2
9 12
24 27

Sample Output:
8
11

*/