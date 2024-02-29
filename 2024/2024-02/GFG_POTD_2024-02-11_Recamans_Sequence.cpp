// GFG POTD 2024/02/11
// Recamans Sequence
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> recamanSequence(int n) {
        set<int> s;
        s.insert(0);
        vector<int> ans;
        ans.push_back(0);

        for(int i = 1; i < n; i++) {
            int a = ans[i - 1] - i;
            if(a <= 0 || s.find(a) != s.end())
                a += 2 * i;
            s.insert(a);
            ans.push_back(a);
        }

        return ans;
    }
};

int main() {
    Solution ob;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> ans = ob.recamanSequence(n);
        for(int i: ans)
            cout << i << ' ';
        cout << endl;
    }
}

/* Sample Input:
2
3
5

Sample Output:
0 1 3 
0 1 3 6 2 

*/