#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool isPrime(int n)
    {
        if(n<=1)
            return false;
        if(n==2 || n==3)
            return true;
        if(n%2==0 || n%3==0)
            return false;
        for(int i=5;i*i<=n;i += 2)
            if(n%i==0) 
                return false;
        return true;
    }
    int firingEmployees(vector<int> &arr, int n){
        vector<vector<int>> vec;
        for(int i=0; i<n; i++)
            vec.push_back({arr[i], i+1});
        vector<vector<int>> vec1;
        for(int i=0; i<=n; i++)
            vec1.push_back({});
        for(int i=0; i<vec.size(); i++)
            vec1[vec[i][0]].push_back(vec[i][1]);
        queue<pair<int,int>> Q;
        int startNode = vec1[0][0];
        Q.push({startNode, 0});
        int cnt = 0;
        vector<int> visited(n+1, 0);
        visited[startNode]=1;
        while(!Q.empty()){
            pair<int,int> front = Q.front();
            Q.pop();
            int node = front.first;
            int level = front.second;
            
            if(node!=startNode)
                if(isPrime(node+level))
                    cnt++;
            
            for(int i = 0;i<vec1[node].size();i++)
                if(!visited[vec1[node][i]]) {
                    visited[vec1[node][i]] = 1;
                    Q.push({vec1[node][i], level+1});
                }
        }
        return cnt;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        
        for(int i=0; i<n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.firingEmployees(arr, n) << endl;
    }
    return 0;
}