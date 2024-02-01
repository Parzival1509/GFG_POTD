// GFG POTD 2023/03/10
// Maximum Triplet Product
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll maxTripletProduct(ll arr[], int n) {
        ll mx1 = INT_MIN, mx2 = mx1, mx3 = mx1;
        ll mn1 = INT_MAX, mn2 = mn1;

        for(int i = 0; i < n; i++) {
            ll el = arr[i];

            // Finding the maximum 3 values
            if(el >= mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = el;
            }
            else if(el >= mx2) {
                mx3 = mx2;
                mx2 = el;
            }
            else if(el >= mx3)
                mx3 = el;

            // Finding the minimum 2 values
            if(el <= mn1) {
                mn2 = mn1;
                mn1 = el;
            }
            else if(el <= mn2)
                mn2 = el;
        }
        return max(mx1 * mx2 * mx3, mn1 * mn2 * mx1);
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,i;
        cin>>n;
        ll arr[n];
        for(i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.maxTripletProduct(arr, n)<<endl;
    }
    return 0;
}

/* Sample Input:
2
4
1 2 3 5
7
-3 -5 1 0 8 3 -2

Sample Output:
30
120

*/