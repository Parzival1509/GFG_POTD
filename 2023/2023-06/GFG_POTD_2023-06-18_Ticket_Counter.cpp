// GFG POTD 2023/06/18
// Ticket Counter
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeTicket(int n, int k) {
        int top = 1, down = n, i = 0;
        while(top < down) {
            if(i % 2 == 0) {
                if(top + k > down) return down;
                else top+=k;
            }
            else {
                if(down - k < top) return top;
                else down -= k;
            }
            i++;
        }
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N, K;
        cin >> N >> K;
        Solution obj;
        int res = obj.distributeTicket(N, K);
        cout<<res<<endl;
    }
}

/* Sample Input:
4
9 3
5 1
14 9
10 10

Sample Output:
6
3
10
10

*/