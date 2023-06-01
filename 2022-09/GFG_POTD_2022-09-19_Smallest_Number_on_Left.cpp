// GFG POTD Smallest Number on left

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> left(n), ans(n);
        stack<int> s;
        s.push(0);
        for(int i=1; i<n; i++){
            if(a[s.top()]<a[i]){
                left[i]=s.top();
                s.push(i);
            }
            else{
                while(!s.empty() && a[s.top()]>=a[i])
                    s.pop();
                if(s.empty())
                    left[i]=0;
                else
                    left[i]=s.top();
                s.push(i);
            }
        }
        for(int i=0; i<n; i++){
            if(a[left[i]]>=a[i])
                ans[i]=-1;
            else
                ans[i]=a[left[i]];
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
3
1 6 2
6
1 5 0 3 4 5

Sample Output
-1 1 1 
-1 1 -1 0 3 4 

*/