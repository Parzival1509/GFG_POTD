#include<bits/stdc++.h>
using namespace std;

void dfs(int source ,vector<int> graph[] , std::vector<bool>& visited)
{
	if(visited[source])return ;
	visited[source] =  true ;
	for(auto el:graph[source])
	{
		dfs(el,graph,visited) ;
	}
}

int numProvinces(vector<vector<int>> adj, int V) {
    std::vector<int> graph[501];
    std::vector<bool> visited(501,false);
	for(int i=0;i<adj.size();++i)
	{
		for(int j =0 ;j<adj[0].size();++j)
		{
			if(adj[i][j] == 1)
			{
				int a = i+1 ;
			   int b = j+1 ;
			   graph[a].push_back(b) ;
			}
		}
	}
	int ct = 0 ;
	for(int i=1;i<=V;++i)
	{
		if(!visited[i])
		{
			dfs(i,graph,visited);
			ct++ ;
		}
	}
	return ct;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int v;
	cin>>v;
	vector<vector<int>> adj;
	vector<int> nums;
	for(int i=0;i<v;++i){
		for(int j=0;j<v;++j){
			int x;
			cin>>x;
			nums.push_back(x);
		}
		adj.push_back(nums);
		nums.clear();
	}

	cout<<numProvinces(adj,v)<<endl;
}