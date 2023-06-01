// GFG POTD 2023/01/01
// Count Even Length
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
	int m = 1e9+7;
	long long binpow(long long a, long long b) {
        a %= m;
        long long res = 1;
        while(b > 0) {
            if(b & 1)
                res = res*a%m;
            a = a*a%m;
            b >>= 1;
        }
        return res;
    }
    
	int compute_value(int n) {
	    long long ans=1, num=1, den=1, cur=n;
	    for(int i=1, j=n; i<=n; i++, j--) {
	        num = (num*j)%m;
	        den = (den*i)%m;
	        
	        long long temp = (num*binpow(den, m-2))%m;
	        temp = binpow(temp, 2);
	        ans = (ans + temp) % m;
	    }
	    return (int)ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}

/* Sample Input
2
1
2

Sample Output
2
6

*/