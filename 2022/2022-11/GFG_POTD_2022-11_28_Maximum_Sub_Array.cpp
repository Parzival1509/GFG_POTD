// GFG POTD 2022/11/28
// Maximum Sub Array

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> findSubarray(int a[], int n) {
        vector<int> ans={-1};
        int sum = 0;
        int l=0, r=0;
        while(l<n && r<n) {
            if(a[l]<0) {
                l++;
                continue;
            }
            else if(a[l]>=0) {
                r=l;
                int currSum = 0;
                vector<int> temp;
                while(r<n && a[r]>=0) {
                    currSum+=a[r];
                    temp.push_back(a[r]);
                    r++;
                }
                if(currSum>sum) {
                    sum = currSum;
                    ans = temp;
                }
                l = r;
            }
        }
        return ans;
    }
};

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

/* Sample Input
2
3
1 2 3
2
-1 2

Sample Output
1 2 3 
2 

*/