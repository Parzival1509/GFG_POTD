// GFG POTD 2023/07/15
// Delete Middle Element of a Stack
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(stack<int>& s, int n, int target, int k) {
        if(target == n - k) {
            s.pop();
            return ;
        }
        
        int a = s.top();
        s.pop();
        helper(s, n, target + 1, k);
        s.push(a);
    }
    
    void deleteMid(stack<int>& s, int sizeOfStack) {
        int k = (sizeOfStack + 1) / 2;
        helper(s, sizeOfStack + 1, 1, k);
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;
        for(int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);    
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while(!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }   
    return 0;
}

/* Sample Input:
2
5
1 2 3 4 5
4
1 2 3 4

Sample Output:
5 4 2 1 
4 3 1 

*/