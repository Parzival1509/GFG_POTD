// GFG POTD 2022/11/11
// Prime Sum

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int num){
        if(num==2 || num==3)
            return true;
        if(num<2 || num%2==0 || num%3==0)
            return false;
        for(int i=5; i*i<=num; i+=2)
            if(num%i == 0)
                return false;
        return true;
    }
    
    string isSumOfTwo(int n){
        for(int i=1; i<=n/2; i++)
            if(isPrime(i) && isPrime(n-i))
                return "Yes";
        return "No";
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

/* Sample Input
2
34 23

Sample Output

*/