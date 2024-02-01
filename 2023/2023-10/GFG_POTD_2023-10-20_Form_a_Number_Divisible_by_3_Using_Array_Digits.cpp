// GFG POTD 2023/10/20
// Form a Number Divisible by 3 Using Array Digits
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPossible(int n, int arr[]) {
        long long sum = 0;
        for(int i = 0; i < n; i++)
            sum += arr[i];
        
        return (sum % 3 == 0);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}

/* Sample Input:
2
3
40 50 90
2
1 4

Sample Output:
1
0

*/