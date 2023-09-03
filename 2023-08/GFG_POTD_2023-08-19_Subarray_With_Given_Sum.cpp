// GFG POTD 2023/08/19
// Subarray With Given Sum
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subarraySum(vector<int>arr, int n, int s) {
        if(s == 0) return {-1};
        
        int i = 0, j = 0, sum = arr[0];
        while(j < n) {
            if(sum == s) return {i + 1, j + 1};
            
            if(sum < s) sum += arr[++j];
            else {
                if(i < j) {
                    sum -= arr[i];
                    i++;
                }
                else {
                    i++;
                    j++;
                    sum = arr[i];
                }
            }
        }
        
        return {-1};
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, s;
        cin >> n >> s;
        vector<int> arr(n);
        int mx = 1e9;
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);
        for(int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
3
5 12
1 2 3 7 5
10 15
1 2 3 4 5 6 7 8 9 10
4 0
1 2 3 4

Sample Output:
2 4 
1 5 
-1 

*/