// GFG POTD 2024/02/19
// Game With String
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minValue(string s, int k) {
        vector<int> freq(26);
        for (char ch : s)
            freq[ch - 'a']++;
        
        priority_queue<int> pq;
        for (auto it : freq)
            if (it) pq.push(it);
        
        while (k) {
            int freq = pq.top();
            pq.pop();
            --freq;
            k--;
            pq.push(freq);
        }

        int ans = 0;
        while (!pq.empty()) {
            ans += pq.top() * pq.top();
            pq.pop();
        }

        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        Solution ob;
        cout << ob.minValue(s, k) << "\n";
    }

    return 0;
}

/* Sample Input:
2
abccc 1
aabcbcbcabcc 3

Sample Output:
6
27

*/