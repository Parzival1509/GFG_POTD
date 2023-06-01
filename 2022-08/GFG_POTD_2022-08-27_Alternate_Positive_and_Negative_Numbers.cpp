// GFG POTD 2022/08/27
// Alternate Positive and Negative Numbers
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> pn, nn;
    void rearrange(int arr[], int n) {
        for(int i=0; i<n; i++)
            if(arr[i] >= 0)
                pn.push_back(arr[i]);
            else
                nn.push_back(arr[i]);
                
        int j=0, p1=0, p2=0;
        while(p1<pn.size() && p2<nn.size())
            if(j%2 == 0)
                arr[j++] = pn[p1++];
            else
                arr[j++] = nn[p2++];
        
        while(p1<pn.size())
            arr[j++] = pn[p1++];
        while(p2<nn.size())
            arr[j++] = nn[p2++];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/* Sample Input
2
9
9 4 -2 -1 5 0 -5 -3 2
10
-5 -2 5 2 4 7 1 8 0 -8

Sample Output
9 -2 4 -1 5 -5 0 -3 2 
5 -5 2 -2 4 -8 7 1 8 0 

*/