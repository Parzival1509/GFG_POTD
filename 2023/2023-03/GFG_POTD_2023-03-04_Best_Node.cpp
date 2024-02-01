// GFG POTD 2023/03/04
// Best Node
// Medium

#include<bits/stdc++.h>
using namespace std;

class Array {
public:
    template <class T>
    static void input(vector<T> &A,int n) {
        for (int i = 0; i < n; i++)
            scanf("%d ",&A[i]);
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

#define ll long long

class Solution {
public:
  
    //positive stores the best value by starting this node with positive value
    //neg stores the best value by starting this node with negative value
    
    // u is current node   and  v  is child nodes
    // for all child nodes for current node combine pos[u] with maximal neg[child] val
    //                                          and neg[u] with maximal pos[child] val
    
    //since sequence pattern (+ - + -) starts from positive, only update ans by comparing with pos[u]
    
    void dfs(int u, vector<int> g[], vector<int> &a, vector<ll> &neg, vector<ll> &pos, ll &ans) {
        pos[u] = a[u - 1];
        neg[u] = -a[u - 1];
        ll bestpos = -1e18, bestneg = -1e18;
        for(auto &v: g[u]) {
            dfs(v, g, a, neg, pos, ans);
            bestpos = max(bestpos, pos[v]);
            bestneg = max(bestneg, neg[v]);
        }
        
        if(bestpos != -1e18) {
            neg[u] += bestpos; 
            pos[u] += bestneg;
        }
        
        ans = max(ans, pos[u]);
    }
    
    ll bestNode(int n, vector<int>&a, vector<int>&p) {
        vector<int>g[n + 1];
        for(int i=1; i<n; i++)
            g[p[i]].push_back(i + 1);
        
        ll ans = -1e18;
        vector<ll> neg(n + 1), pos(n + 1);
        dfs(1, g, a, neg, pos, ans);
        return ans;
    }
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--) {
        int N;
        scanf("%d",&N);
        vector<int> A(N);
        Array::input(A,N);
        vector<int> P(N);
        Array::input(P,N);
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        cout<<res<<endl;
    }
}

/* Sample Input:
2
3
1 2 3
-1 1 1
3
3 1 2
-1 1 2

Sample Output:
3
4

*/