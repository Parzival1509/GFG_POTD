#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool possible(int i , int j , int n)
    {
	    return i>0 and j>0 and i<=n and j<=n ;
    }
    std::vector<pair<int , int>> pat = {
	    {-1,-2},{-1,2},{1,2},{1,-2},{2,1},{2,-1},{-2,1},{-2,-1}
    };
    int bfs(int a , int b , int c , int d ,  int n)
    {
        if(a == c and b == d)
        return 0 ;
	    int dist[n+1][n+1] ;
	    bool visited[n+1][n+1] ;
	    memset(visited,false , sizeof visited) ;
	    visited[a][b] = true ;
    
	    dist[a][b] = 0 ;
	    queue<pair<int,int>> q ;
	    q.push({a,b}) ;
        
        bool fl = false ;
    
	    while(!q.empty())
	    {
		    int x = q.front().first ;
		    int y = q.front().second ;
		    q.pop() ;
		    for(auto el:pat)
		    {
			    int i = el.first ;
			    int j = el.second ;
			    int ci = x+i ;
			    int cj = y+j ;
		        // cout<<ci<<" "<<cj<<endl;
			    if(!possible(ci, cj, n) || visited[ci][cj])continue ;
			    visited[ci][cj] = true ;
			    dist[ci][cj] = dist[x][y] + 1 ;
			    if(ci == c and cj == d)
			    {
				    fl = true ;
				    break;
			    }
                q.push({ci,cj}) ;
		    }
		    if(fl)
		        break;
	    }
	    if(fl)
	        return dist[c][d] ;
        return -1 ;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    int a , b ;
	    int c , d ;
	    a = KnightPos[0] ;
	    b = KnightPos[1] ;
	    c = TargetPos[0] ;
	    d = TargetPos[1] ;
        int ans = bfs(a,b,c,d ,N) ;
        return ans ;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}