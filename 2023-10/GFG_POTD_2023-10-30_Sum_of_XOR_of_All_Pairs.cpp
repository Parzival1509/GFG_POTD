// GFG POTD 2023/10/30
// Sum of XOR of All Pairs
// Medium

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll sumXOR(int arr[], int n) {
        ll sum = 0, i = 0;
        while(i < 32) {
            ll ones = 0, zeros = 0;
            for(int j = 0; j < n; j++) {
                if(arr[j] & (1 << i)) ones++;
                else zeros ++;
            }
            
            sum += ones * zeros * (1 << i);
            i++;
        }
        
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int arr[n + 1];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.sumXOR(arr, n) << endl;
    }   

    return 0;
}

/* Sample Input:
3
3
7 3 5
4
5 9 7 6
5
1 2 1 2 1

Sample Output:
12
47
18

*/