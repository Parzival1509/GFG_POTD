// GFG POTD Modified Numbers and Queries

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool checkPrime(int n){
        if(n<=1)
            return false;
        for(int i=2; i*i<=n; i++)
            if(n%i == 0)
                return false;
        return true;
    }
    
    int primeSum(int n){
        int sum = 0;
        if(n<4)
            return n;
        for(int i=1; i<=n; i++)
            if(n%i == 0)
                if(checkPrime(i))
                    sum += i;
        return sum;
    }
    int sumOfAll(int l, int r){
        int sum = 0;
        for(int i=l ; i<=r; i++)
            sum += primeSum(i);
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin>>l>>r;
        Solution ob;
        cout<<ob.sumOfAll(l,r)<<endl;
    }
    return 0;
}

/* Sample Input
3
1 2
1 6
4 13

Sample Output
3
18
60

*/