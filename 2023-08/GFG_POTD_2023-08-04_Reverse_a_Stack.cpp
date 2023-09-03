// GFG POTD 2023/08/04
// Reverse a Stack
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Reverse(stack<int> &st) {
        vector<int> v;
        while(!st.empty()) {
            v.push_back(st.top());
            st.pop();
        }
        
        for(int i = 0; i < v.size(); i++)
            st.push(v[i]);
    }
};

int main(){
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        stack<int> St;
        for(int i = 0; i < N; i++) {
            int x;
            cin >> x;
            St.push(x);
        }

        Solution ob;
        ob.Reverse(St);
        vector<int> res;
        while(St.size()) {
            res.push_back(St.top());
            St.pop();
        }

        for(int i = res.size() - 1; i >= 0; i--)
            cout << res[i] << " ";
        cout << endl;
    }
}

/* Sample Input:
2
5
3 2 1 7 6
4
4 3 9 6

Sample Output:
6 7 1 2 3 
6 9 3 4 

*/