// GFG POTD Composite and Prime

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isprime(int n){
        if(n==1)return 0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            return 0;
        }
        return 1;
    }
    int Count(int L, int R){
        int p=0,c=0;
        for(int i=L;i<=R;i++)
        {
            if(isprime(i))
                p++;
            else if(i>3)
                c++;
        }
        return c-p;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int L, R;
        cin >> L >> R;
        Solution obj;
        int ans = obj.Count(L, R);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
4 6
4 4

Sample Output
1
1

*/