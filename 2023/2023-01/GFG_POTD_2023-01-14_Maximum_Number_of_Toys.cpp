// GFG POTD 2023/01/14
// Maximum Number of Toys
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binary_search(long long l, long long h, int mid, long long target, vector<long long> &A) {
        while(l <= h) {
            mid = (l+h)/2;
            if(A[mid] <= target) l = mid+1;
            else h = mid-1;
        }
        return l-1;
    }
    
    vector<int> maximumToys(int N,vector<int> &B,int Q,vector<vector<int>> &q){
        vector<long long> A(begin(B), end(B));
        sort(begin(A), end(A));
        for(int i=1; i<N; i++)
            A[i] += A[i-1];
        vector<int> ans;
      
        for(auto &x: q) {
            long long c=x[0];
            int idx = binary_search(0, N-1, 0, c, A);
            int i = 2,k = x[1];
            if(idx == -1) {
                ans.push_back(0);
                continue;
            }

            priority_queue<int> pq;
            while(k--)
                pq.push(-B[x[i++]-1]);
            c -= A[idx];
            idx++;
            while(!pq.empty()) {
                int a =- pq.top();
                pq.pop();
                long long last = 0;
                if(idx == 1) last = A[0];
                else last = A[idx-1]-A[idx-2];
                if(a > last) {
                    pq.push(0);
                    break;
                }
        
                c += a;
                while(idx<N && c>=A[idx]-A[idx-1]) {
                    c -= A[idx]-A[idx-1];
                    idx++;
                }
            }
            ans.push_back(idx-(x[1]-pq.size()));
        }
        return ans;
    }
};

int main() {
	int t=1;
	cin>>t;
	for(int i=1; i<=t; i++) {
	    int N;
	    cin>>N;
	    vector<int> A(N);
	    for(auto &i: A) cin>>i;
	    int Q;
	    cin>>Q;
	    vector<vector<int>> Queries(Q);
	    for(int i=0; i<Q; i++) {
		    int x, y;
		    cin>>x>>y;
		    Queries[i].push_back(x);
		    Queries[i].push_back(y);
		    for(int j=0; j<Queries[i][1]; j++) {
		        cin>>x;
		        Queries[i].push_back(x);
	      	}
	    }
	    Solution obj;
	    auto ans = obj.maximumToys(N, A, Q, Queries);
	    for(auto i: ans)
	      	cout<<i<<" ";
	    cout<<endl;
 	}
}

/* Sample Input
2
5
8 6 9 2 5
2
12 2 3 4
30 0
2
3 3
1
1 0

Sample Output
2
0

*/