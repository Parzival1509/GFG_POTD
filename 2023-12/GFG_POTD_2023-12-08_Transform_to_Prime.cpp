// GFG POTD 2023/12/08
// Transform to Prime
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPrime(int n) {
        if(n == 1) return false;
        if(n < 4) return true;
        
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0) return false;
            
        return true;
    }

    int minNumber(int a[], int n) {
        int sum = 0, ans = 0;
        for(int i = 0; i < n; i++)
            sum += a[i];
            
        while(1) {
            if(checkPrime(sum + ans))
                break;
            ans++;
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }

    return 0;
}

/* Sample Input:
3
5
2 4 6 8 12
3
1 0 0
3
1 5 7

Sample Output:
5
1
0

*/