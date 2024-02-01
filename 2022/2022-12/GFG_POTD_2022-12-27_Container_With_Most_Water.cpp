// GFG POTD 2022/12/27
// Container With Most Water
// Medium

#include<bits/stdc++.h>
using namespace std;

long long maxArea(long long arr[], int len) {
    int i=0, j=len-1;
    long long ans=0;
    while(i<j) {
        long long tmp = (long long)(j-i)*min(arr[i], arr[j]);
        ans = max(ans, tmp);
        if(arr[i] < arr[j]) i++;
        else j--;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
    return 0;
}

/* Sample Input
2
4
1 5 4 3
5
3 1 2 4 5

Sample Output
6
12

*/