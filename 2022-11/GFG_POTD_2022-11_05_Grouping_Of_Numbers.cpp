// GFG POTD 2022/11/05
// Grouping Of Numbers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxGroupSize(int a[], int n, int k) {
        int fr[k]={0};
        for(int i=0; i<n; i++)
            fr[a[i]%k]++;
        if(k%2==0)
            fr[k/2]=min(fr[k/2], 1);
        int res = min(fr[0], 1);
        for(int i=1; i<=k/2; i++)
            res += max(fr[i], fr[k-i]);
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}

/* Sample Input
3
4 8
1 7 2 6
2 3
1 2
11 6
1 1 2 3 2 4 5 6 7 8 5

Sample Output
2
1
8

*/