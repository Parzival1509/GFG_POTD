// GFG POTD 2023/06/08
// Find Kth Permutation
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // // Approach 1: Using in-built next_permutation function
    // string kthPermutation(int n, int k) {
    //     vector<int> v;
    //     for(int i = 1; i <= n; i++)
    //         v.push_back(i);
    //     int count = 1;
    //     while(count != k) {
    //         next_permutation(v.begin(), v.end());
    //         count++;
    //     }
    //     string s = "";
    //     for(int i = 0; i < v.size(); i++)
    //         s = s + to_string(v[i]);
    //     return s;
    // }
    
    // Approach 2:
    string kthPermutation(int n, int k) {
        vector<int>numbers;
        int fact = 1;
        for(int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k--;
        
        while(true) {
            ans += to_string(numbers[k/fact]);
            numbers.erase(numbers.begin() + k/fact);
            if(numbers.size() == 0)
                break;
            k %= fact;
            fact /= numbers.size();
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

/* Sample Input:
2
4 3
3 5

Sample Output:
1324
312

*/