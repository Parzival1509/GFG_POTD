// GFG POTD 2022/07/21
// Get Min at Pop
// Easy

#include <bits/stdc++.h>
using namespace std;

stack<int> _push(int arr[],int n);
void _getMinAtPop(stack<int>s);

//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n) {
    stack<int> st;
    st.push(arr[0]);
    for(int i=1; i<n; i++)
        st.push(min(st.top(), arr[i]));
    return st;
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s) {
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        stack<int>mys=_push(arr,n);
        _getMinAtPop(mys);
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
5
1 2 3 4 5
7
1 6 43 1 2 0 5

Sample Output
1 1 1 1 1 
0 0 1 1 1 1 1 

*/