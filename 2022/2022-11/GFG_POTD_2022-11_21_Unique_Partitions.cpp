// GFG POTD 2022/11/21
// Unique Partitions

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<int>>vec;
    vector<int>v;

    void fun(int n, int arr[], int i, int s) {
        if(s>n || i>=n)
        return ;
        if(s == n) {
            vec.push_back(v);
            return ;
        }
        v.push_back(arr[i]);
        fun(n, arr, i, s+arr[i]);
        v.pop_back();
        fun(n, arr, i+1, s);
    }

    vector<vector<int>> UniquePartitions(int n) {
        int arr[n];
        int i,s=0;
        for(i=1; i<=n; i++)
            arr[i-1]=i;
        i=0;
        fun(n, arr, i, s);   
        for(i=0; i<vec.size(); i++)
            sort(vec[i].begin(), vec[i].end(), greater<int>());
        sort(vec.rbegin(), vec.rend());
        return vec;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        Solution ob;
        vector<vector<int>> ans = ob.UniquePartitions(n);
        for(auto i : ans)
            for(auto j: i)
                cout << j <<" ";
        cout << "\n";
    }  
    return 0;
}

/* Sample Input
3
3
4
5

Sample Output
3 2 1 1 1 1 
4 3 1 2 2 2 1 1 1 1 1 1 
5 4 1 3 2 3 1 1 2 2 1 2 1 1 1 1 1 1 1 1 

*/