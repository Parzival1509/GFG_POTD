// GFG POTD Stack Permutations
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int isStackPermutation(int n, vector<int> &a, vector<int> &b){
        stack<int> st;
        int j=0;
        for(int i=0; i<n; i++){
            st.push(a[i]);
            while(!st.empty() && st.top()==b[j]){
                st.pop();
                j++;
            }
        }
        if(st.empty() && j==n)
            return 1;
        return 0;
    }
};

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        Solution ob;
        cout<<ob.isStackPermutation(n,a,b)<<endl;
    }
    
    return 0;
}

/*
Sample Input:
2
3
1 2 3
2 1 3
3
1 2 3
3 1 2

Sample Output:
1
0

*/