// GFG POTD 2023/03/16
// Second Smallest Number
// Medium

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    string secondSmallest(int s, int d) {
        if(s >= 9*d) return "-1";
        if(s==1 || d==1) return "-1";
        
        string ans(d, '0');
        int sum = s, last = -1;
        
        // Finding the smallest no.
        for(int i=d-1; i>=0; i--) {
            if(sum > 9) {
                ans[i] = '9';
                sum -= 9;
            }
            else if(sum > 0) {
                ans[i] = '0' + sum;
                sum = 0;
                last = i;
            }
            else break;
        }
        if(ans[0] == '0') {
            ans[0] = '1';
            ans[last] -= 1;
        }

        // Finding the 2nd Smallest no.
        int l = d-2;
        while(ans[l] == '9') l--;
        ans[l] += 1;
        ans[l+1] -= 1;
        return ans;
    }
};

int main() { 
    int t;
    cin>>t;
    while(t--) {
        int S, D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S, D) << endl;
    }
    return 0; 
} 

/* Sample Input:
2
9 2
16 3

Sample Output:
27
178

*/