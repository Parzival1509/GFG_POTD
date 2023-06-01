// GFG POTD 2023/01/16
// Next Greater Element
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n) {
        stack<long long> st;
        st.push(-1);
        vector<long long> ans(n);
        for(int i=n-1; i>=0; i--) {
            long long curr = arr[i];
            while(st.top() != -1 && st.top() <= curr) st.pop();
            ans[i] = st.top();
            st.push(curr);
        }
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        vector <long long> res = ob.nextLargerElement(arr, n);
        for(long long i: res) cout<<i<<" ";
        cout<<endl;
    }
	return 0;
}

/* Sample Input
2
4
1 3 2 4
5
6 8 0 1 3

Sample Output
3 4 4 -1 
8 -1 1 3 -1 

*/