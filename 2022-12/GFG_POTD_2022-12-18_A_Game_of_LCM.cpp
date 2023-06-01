// GFG POTD 2022/12/18
// A Game of LCM
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxGcd(long long n) {
        long long ans1=n*(n-1), ct=0, b1=ans1, ans2=(n-1)*(n-2), b2=ans2;
        b1 *= (n-2) / __gcd(ans1, (n-2));
        b1 *= (n-3) / __gcd(ans1, (n-3));
        for(long long i=n-2; i>2; i--) {
            if(__gcd(ans1, i)==1) {
                ans1 *= i;
                ct++;
            }
            if(ct==2) break;
        }
        ct=0;
        b2 *= (n-3) / __gcd(ans2, (n-3));
        b2 *= (n-4) / __gcd(ans2, (n-4));
        for(long long i=n-3; i>2; i--) {
            if(__gcd(ans2, i)==1) {
                ans2 *= i;
                ct++;
            }
            if(ct==2) break;
        }
        return max(max(ans1, b1), max(ans2, b2));
    }
    
    // // Code Freaks Sol
    // long long maxGcd(long long n) {
    //     long long ans1=n*(n-1), ct=0, b1=ans1, ans2=(n-1)*(n-2), b2=ans2;
    //     b1 *= (n-2) / __gcd(ans1, (n-2));
    //     b1 *= (n-3) / __gcd(ans1, (n-3));
    //     for(long long i=n-2; i>2; i--) {
    //         if(__gcd(ans1, i)==1) {
    //             ans1 *= i;
    //             ct++;
    //         }
    //         if(ct==2) break;
    //     }
    //     ct=0;
    //     b2 *= (n-3) / __gcd(ans2, (n-3));
    //     b2 *= (n-4) / __gcd(ans2, (n-4));
    //     for(long long i=n-3; i>2; i--) {
    //         if(__gcd(ans2, i)==1) {
    //             ans2 *= i;
    //             ct++;
    //         }
    //         if(ct==2) break;
    //     }
    //     return max(max(ans1, b1), max(ans2, b2));
    // }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}

/* Sample Input
3
4 5 18

Sample Output
12
60
53040

*/