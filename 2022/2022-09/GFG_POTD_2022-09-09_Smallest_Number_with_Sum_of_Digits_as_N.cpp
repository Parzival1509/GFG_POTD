// GFG POTD 2022/09/09
// Smallest Number with Sum of Digits as N and Divisible by 10^N
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string digitsNum(int n){
        string ans="";
        for(int i=0; i<n; i++)
            ans += to_string(0);
        while(n>9){
            ans = to_string(9)+ans;
            n -= 9;
        }
        if(n!=0)
            ans = to_string(n)+ans;
        return ans;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        Solution ob;
        string ans = ob.digitsNum(n);
        cout << ans <<"\n";
    }
    return 0;
}

/* Sample Input
2
5
20

Sample Output
500000
29900000000000000000000

*/