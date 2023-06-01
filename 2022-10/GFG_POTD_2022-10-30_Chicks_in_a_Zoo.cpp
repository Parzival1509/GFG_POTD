// GFG POTD 2022/10/30
// Chicks in a Zoo

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int NoOfChicks(int n){
	    vector<long long> chicks(n+1, 0);
	    chicks[1]=1;
	    long long sum = 1, pre=0;
	    for(int i=2; i<=n; i++){
	    	if(i>=6)
	    		sum -= chicks[pre++];
	    	chicks[i] = 2*sum;
	    	sum += chicks[i];
	    }
	    return sum;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}

/* Sample Input
15
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15

Sample Output
1
3
9
27
81
243
726
2172
6498
19440
58158
173988
520512
1557192
4658580

*/