// GFG POTD 2023/06/17
// Queue Operations
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // Approach 1: Using Recursion
    // void insert(queue<int> &q, int k) {
    //     q.push(k);
    // }
    
    // int findFrequency(queue<int> &q, int k) {
    //     if(q.empty()) return 0;
        
    //     int tmp = q.front(), ct = 0;
    //     q.pop();
    //     if(tmp == k) ct += 1 + findFrequency(q, k);
    //     else ct += findFrequency(q, k);
        
    //     q.push(tmp);
        
    //     return ct;
    // }

    // Approach 2: Using Map
    unordered_map<int, int> hsh;
    
    void insert(queue<int> &q, int k) {
        q.push(k);
        hsh[k]++;
    }
    
    int findFrequency(queue<int> &q, int k) {
        return hsh[k];
    }
};

int main() {
    int testcase;
    cin>>testcase;
    while(testcase-- > 0) {
        queue<int> q;
        int n, k;
        cin>>n;
        Solution obj;
        for(int i = 0;i<n;i++) {
            cin >> k;
            obj.insert(q, k);
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> k;
            int f = obj.findFrequency(q, k);
            if(f != 0) cout<<f<<' ';
            else cout<<"-1 ";
        }
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
8
1 2 3 4 5 2 3 1
5
1 3 2 9 10
6
1 2 1 1 1 4
4
1 5 4 3

Sample Output:
2 2 2 -1 -1 
4 -1 1 -1 

*/