// GFG POTD 2023/03/17
// Number of Subarrays of 0's
// Easy

#include <bits/stdc++.h>
using namespace std;

long long int no_of_subarrays(int n, vector<int> &arr) {
    long ans = 0, cnt = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] == 0) cnt++;
        else {
            ans += ((long)(cnt*(cnt+1))/2);
            cnt = 0;
        }
    if(cnt != 0) ans += ((long)(cnt*(cnt+1))/2);
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << no_of_subarrays(n, arr) << endl;
    }
}

/* Sample Input:
2
4
0 0 1 0
4
0 0 0 0

Sample Output:
4
10

*/