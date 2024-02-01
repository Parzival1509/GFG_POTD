// GFG POTD 2022/12/08
// 3 Divisors
// Medium

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    vector<int> threeDivisors(vector<long long> query, int q) {
        int N = 1000010;
        vector<int> prime(N,1);
        prime[0] = prime[1] = 0;

        // Generating Prime Numbers
        for(int j=2; j<N; ++j)
            if(prime[j])
                for(int k=2*j;k<N;k+=j)
                    prime[k] = 0;

        // Keeping a count of prime no.s
        for(int i=1; i<N; ++i)
            prime[i] = prime[i] + prime[i-1];
           
        vector<int> nums;
        for(int i=0; i<q; ++i){
            int x = sqrt(query[i]);
            nums.push_back(prime[x]);
        }
        return nums;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int q;
        cin>>q;
        vector<long long> query(q);
        for(int i=0; i<q; i++)
            cin>>query[i];
        Solution ob;
        vector<int> ans = ob.threeDivisors(query, q);
        for(auto cnt: ans)
            cout<< cnt << endl;
    }
    return 0;
}

/* Sample Input
1
6
6 10 25 8468 5725 1479

Sample Output
1
2
3
24
21
12

*/