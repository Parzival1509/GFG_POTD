// GFG POTD 2023/12/07
// Number of Subarrays with Maximum Values in Given Range
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long calc(int a[],int n,int more) {
        long ans = 0;
        int prev = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] >= more) {
                int len = i + 1;
                ans += (prev + 1) * 1l * (n - i);
                prev = 0;
            }
            else prev += 1l;
        }
        
        return ans;
    }
    
    long countSubarrays(int a[], int n, int L, int R) {
        long count1 = calc(a, n, R + 1);
        long count2 = calc(a, n, L);
        
        return count2 - count1;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n , l, r;
        cin >> n >> l >> r;
        int a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.countSubarrays(a, n, l, r) << endl;
    }

    return 0;
}

/* Sample Input:
2
5 1 10
2 0 11 3 0
3 2 4
3 4 1

Sample Output:
4
5

*/