// GFG POTD 2023/02/21
// Fill the Matrix
// Medium

#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    int minIteration(int n, int m, int x, int y) {
        int firstcorner = x-1+y-1;
        int secondcorner = x-1+m-y;
        int thirdcorner = n-x+y-1;
        int fourthcorner = n-x+m-y;
        return max(max(firstcorner, secondcorner), max(thirdcorner, fourthcorner));
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
}

/* Sample Input:
2
2 3 2 3
1 1 1 1

Sample Output:
3
0

*/