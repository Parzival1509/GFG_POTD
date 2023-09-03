// GFG POTD 2023/06/07
// Least Prime Factor
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // Approach 1:
    // bool isPrime(int x) {
    //     if(x == 2 || x == 3) return true;
    //     for(int i = 2; i <= sqrt(x); i++)
    //         if(x%i == 0) return false;
            
    //     return true;
    // }
  
    // vector<int> leastPrimeFactor(int n) {
    //     vector<int> prime;
    //     for(int i = 2; i <= n; i++)
    //         if(isPrime(i))
    //             prime.push_back(i);
        
    //     vector<int> ans;
    //     ans.push_back(0);
    //     ans.push_back(1);
        
    //     for(int i = 2; i <= n; i++)
    //         for(int j = 0; j < prime.size(); j++)
    //             if(i%prime[j] == 0) {
    //                 ans.push_back(prime[j]);
    //                 break;
    //             }
        
    //     return ans;
    // }
    
    // Approach 2: Sieve of Eratosthenes
    vector<int> leastPrimeFactor(int n) {
        vector<int> ans(n + 1);
        ans[1] = 1;
    
        for(int i = 2; i <= n; i++)
            ans[i] = i;
    
        // Apply the Sieve of Eratosthenes
        for(int i = 2; i * i <= n; i++)
            if(ans[i] == i)
                for(int j = i * i; j <= n; j += i) {
                    if(ans[j] == j)
                        ans[j] = i;
                }
    
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i = 1; i <= n; i++)
            cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

/* Sample Input:
2
4 6

Sample Output:
1 2 3 2 
1 2 3 2 5 2 

*/