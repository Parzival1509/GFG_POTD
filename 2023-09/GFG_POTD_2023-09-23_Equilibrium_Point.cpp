// GFG POTD 2023/09/23
// Equilibrium Point
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equilibriumPoint(long long arr[], int n) {
        long long sum = 0, currSum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
        
        for(int i = 0; i < n; i++) {
            if(currSum == sum - currSum - arr[i])
                return i + 1;
            currSum += arr[i];
        }
        
        return -1;
    }
};

int main() {
    int t;
    cin >> t;
    Solution ob;
    while(t--) {
        int n;
        cin >> n;
        long long arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        cout << ob.equilibriumPoint(arr, n) << endl;
    }

    return 0;
}

/* Sample Input:
2
5
1 3 5 2 2
1
1

Sample Output:
3
1

*/