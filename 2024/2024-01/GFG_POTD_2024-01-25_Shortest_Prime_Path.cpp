// GFG POTD 2024/01/25
// Shortest Prime Path
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ischeck(int n) {
        if(n % 2 == 0 || n % 3 == 0) return false;
        
        for(int i = 5; i * i <= n; i += 6)
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
        
        return true;
    }
    
    int solve(int num1, int num2) {
      queue<int>q;
      q.push(num1);
      int ans = 0;
      unordered_set<int> st;
      st.insert(num1);
      
      while(q.size()) {
        int n = q.size();
        for(int i = 0; i < n; i++) {
            int x = q.front();
            q.pop();
            if(x == num2) return ans;
            
            for(int j = 0; j < 4; j++) {
                string str = to_string(x);
                for(int k = 0; k < 10; k++) {
                    if(j == 0 && k < 9)
                        str[j] = (k + 1) + '0';
                    else if(j) str[j] = k + '0';
                    
                    int num = stoi(str);
                    if(st.find(num) == st.end() && num <= 10000 && ischeck(num)) {
                        q.push(num);
                        st.insert(num);
                    }
                }
            }
        }
        ans++;
      }
    
      return -1;
    }
};

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int num1, num2;
        cin >> num1 >> num2;
        Solution obj;
        int answer = obj.solve(num1, num2);
        cout << answer << endl;
    }
}

/* Sample Input:
2
1033 8179
1033 1033

Sample Output:
6
0

*/