// GFG POTD 2023/09/26
// Find All Four Sum Numbers
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        if(n < 4) return {};
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++) {
            // Avoiding Duplicates
            if(i > 0 && arr[i] == arr[i - 1]) continue;
                
            for(int j = i + 1; j < n - 2; j++) {
                // Avoiding Duplicates
                if(j > i + 1 && arr[j] == arr[j - 1]) continue;
                    
                int left = j + 1, right = n - 1;

                while(left < right) {
                    int sum = arr[i] + arr[j] + arr[left] + arr[right];
                    
                    if(sum == k) {
                        ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                        
                        left++;
                        // Avoiding Duplicates
                        while(left < right && arr[left] == arr[left - 1]) left++;
                            
                        right--;
                        // Avoiding Duplicates
                        while(left < right && arr[right] == arr[right + 1]) right--;
                    }
                    else if(sum < k) left++;
                    else right--;
                }
            }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for(i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for(auto &v : ans) {
            for(int &u : v)
                cout << u << " ";
            cout << endl;
        }
        if(ans.empty())
            cout << -1 << endl;
        cout << "\n";
    }

    return 0;
}

/* Sample Input:
2
5 3
0 0 2 1 1
7 23
2 3 4 5 7 8 10

Sample Output:
0 0 1 2 

2 3 8 10 
2 4 7 10 
3 5 7 8 


*/