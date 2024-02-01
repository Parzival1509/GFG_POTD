// GFG POTD 2022/11/10
// Jumping Numbers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(long long x, long long num, long long& ans) {
        queue<long long> q;
        q.push(num);
        while(!q.empty()){
            num=q.front();
            q.pop();
            if(num<=x){
                ans = max(ans, num);
                int last=num%10;
                if(last!=9)
                    q.push((num*10)+(last+1));
                if(last!=0)
                    q.push((num*10)+(last-1));
            }
        }
    }
    long long jumpingNums(long long x) {
        long long ans=0;
        for(long long i=1; i<=9 && i<=x; i++)
            bfs(x, i, ans);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        cin>>X;
        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}

/* Sample Input
3
10
50
1200

Sample Output
10
45
1012

*/