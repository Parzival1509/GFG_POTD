// GFG POTD 2023/01/03
// Minimum Number of Students to be Removed
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeStudents(int H[], int N) {
        vector<int> LIS;
        for(int i=0; i<N; i++) {
            auto ind = lower_bound(LIS.begin(), LIS.end(), H[i])-LIS.begin();
            if(ind == LIS.size())
                LIS.push_back(H[i]);
            else LIS[ind] = H[i];
        }
        return N-LIS.size();
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int N;
        cin>>N;
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];
        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}

/* Sample Input
2
3
1 2 3
6
9 1 2 3 1 5

Sample Output
0
2

*/