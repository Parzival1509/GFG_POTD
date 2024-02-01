// GFG POTD 2024/01/27
// Brackets in Matrix Chain Multiplication
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printOrder(char order[][26], int i, int j, string &result) {
        if (i == j) {
            result += ('A' + i - 1);
            return;
        }
        
        result += '(';
        printOrder(order, i, order[i][j] - 'A' + 1, result);
        printOrder(order, order[i][j] - 'A' + 2, j, result);
        result += ')';
    }
    
    string matrixChainOrder(int p[], int n) {
        int dp[n][n];
        char order[n][26];
        
        for (int i = 1; i < n; i++)
            dp[i][i] = 0;
        
        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        order[i][j] = 'A' + k - 1;
                    }
                }
            }
        }
        
        string result = "";
        printOrder(order, 1, n - 1, result);
        
        return result;
    }
};

int get(int p[],int n) {
    int m[n][n], ans = 1e9; 
    for (int i = 1; i < n; i++)
        m[i][i] = 0; 
    for (int L = 2; L < n; L++)
        for (int i = 1; i < n - L + 1; i++) { 
            m[i][i + L - 1] = INT_MAX; 
            for (int k = i; k <= i + L - 2; k++){ 
                int q = m[i][k] + m[k + 1][i + L - 1] + p[i-1] * p[k] * p[i + L - 1]; 
                if (q < m[i][i + L - 1])
                    m[i][i + L - 1] = q;
            }
        }

    return m[1][n - 1];
}

int find(string s,int p[]) {
    vector<pair<int, int>> arr;
    int ans = 0;
    for(auto t: s) {
        if(t == '(')
            arr.push_back({-1, -1});
        else if(t == ')') {
            pair<int, int> b = arr.back();
            arr.pop_back();
            pair<int, int> a = arr.back();
            arr.pop_back();
            arr.pop_back();
            arr.push_back({a.first, b.second});
            ans += a.first * a.second * b.second;
        }
        else arr.push_back({p[int(t - 'A')], p[int(t - 'A') + 1]});
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p[n];
        for(int i = 0; i < n; i++)
            cin >> p[i];
        Solution ob;
        string result = ob.matrixChainOrder(p, n);
        if(find(result, p) == get(p, n))
            cout << "True" << endl;
        else cout << "False" << endl;
    }

    return 0;
}

/* Sample Input:
2
5
40 30 20 10 30
3
3 3 3

Sample Output:
True
True

*/