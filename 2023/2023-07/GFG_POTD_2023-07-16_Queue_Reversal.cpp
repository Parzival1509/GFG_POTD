// GFG POTD 2023/07/16
// Queue Reversal
// Basic

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    queue<int> rev(queue<int> q) {
        stack<int> st;
        while(!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        while(!st.empty()) {
            q.push(st.top());
            st.pop();
        }
        return q;
    }
};

int main() {
    int test;
    cin >> test; 
    while(test--) {
        queue<int> q; 
        int n, var; 
        cin >> n; 
        while(n--) {
            cin >> var; 
            q.push(var);
        }
        Solution ob;
        queue<int> a = ob.rev(q); 
        while(!a.empty()) {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl; 
    }
}

/* Sample Input:
2
6
4 3 1 10 2 6
4
4 3 2 1

Sample Output:
6 2 10 1 3 4 
1 2 3 4 

*/