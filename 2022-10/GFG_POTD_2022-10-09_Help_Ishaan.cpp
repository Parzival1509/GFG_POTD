// GFG POTD Help Ishaan

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n){
        if(n<2)
            return false;
        if(n<4)
            return true;
        if(n%2==0)
            return false;
        for(int i=3; i*i<=n; i+=2)
            if(n%i==0)
                return false;
        return true;
    }
    int NthTerm(int n){
        if(isPrime(n))
            return 0;
        int f, b, fn=n+1, bn=n-1, i=1;
        while(!isPrime(n+i) && !isPrime(n-i))
            i++;
        return i;

        // Edge Case 1
        // if(n==1)
        //     return 1;
        // while(true){
        //     if(isPrime(bn)){
        //         b=n-bn;
        //         break;
        //     }
        //     bn--;
        // }
        // while(true){
        //     if(isPrime(fn)){
        //         f=fn-n;
        //         break;
        //     }
        //     fn++;
        // }
        // return min(f, b);
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int N;
        cin >> N;
        Solution obj;
        int ans = obj.NthTerm(N);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input2
2
10
7

Sample Output
1
0

*/