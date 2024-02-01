// GFG POTD 2023/06/03
// Find Maximum Equal Sum of Three Stacks
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEqualSum(int n1, int n2, int n3, vector<int> &s1, vector<int> &s2, vector<int> &s3) {
        int sum1 = accumulate(s1.begin(), s1.end(), 0);
        int sum2 = accumulate(s2.begin(), s2.end(), 0);
        int sum3 = accumulate(s3.begin(), s3.end(), 0);

        int i = 0, j = 0, k = 0;
        while(i < n1 && j < n2 && k < n3) {
            if(sum1 == sum2 && sum2 == sum3) return sum1;

            if(sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= s1[i];
                i++;
            }
            else if(sum2 >= sum3 && sum2 >= sum1) {
                sum2 -= s2[j];
                j++;
            }
            else if(sum3 >= sum1 && sum3 >= sum2) {
                sum3 -= s3[k];
                k++;
            }
        }

        return 0;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n1, n2, n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1), s2(n2), s3(n3);
        for(int i = 0; i < n1; i++)
            cin>>s1[i];
        for(int i = 0; i < n2; i++)
            cin>>s2[i];
        for(int i = 0; i < n3; i++)
            cin>>s3[i];
        Solution ob;
        int ans = ob.maxEqualSum(n1, n2, n3, s1, s2, s3);
        cout<<ans<<endl;
    }
    return 0;
}

/* Sample Input:
3

3 4 2
4 2 3
1 1 2 3
1 4

2 1 3
4 7
10
1 2 3

2 3 1
3 4
1 1 5
7

Sample Output:
5
0
7

*/