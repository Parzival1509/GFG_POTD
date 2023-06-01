// GFG POTD 2023/04/29
// Find Number
// Medium

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    // // Approach 1: Using Recursion
    // ll help(ll n) {
    //     if(n < 6) return n + (n - 1);
    //     if(n%5 == 0) return ((help((n/5) - 1))*10) + 9;
    //     return (help(n/5)*10) + (n%5) + (n%5) - 1;
    // }

    // ll findNumber(ll n) {
    //     return help(n);
    // }
    
    // Approach 2: Without Recursion
    ll findNumber(ll n) {
        int lst[] = {9, 1, 3, 5, 7};
        ll num = 0, p = 1;
        while(n != 0) {
            int rem = n % 5;
            num = num + lst[rem] * p;
            if(n % 5 == 0) n--;
            p *= 10;
            n /= 5;
        }
        return num;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}

/* Sample Input:
2
3
13

Sample Output:
5
35

*/