// GFG POTD 2023/01/11
// Make Array Elements Unique
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long int minIncrements(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        long long ct=0, mx=0;
        for(int i=0; i<n; i++)
        	if(arr[i] > mx) mx = arr[i];
        	else {
        		mx++;
        		ct += mx-arr[i];
        	}
        return ct;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}

/* Sample Input
4
3
1 2 2
4
1 1 2 3
5
1 1 3 4 5
6
1 1 4 4 6 6

Sample Output
1
3
1
3

*/