// GFG POTD 2023/04/05
// Count Special Numbers
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialNumbers(int N, vector<int> a) {
        int count = 0;
        map<int, int> m;
        for(int i=0; i<a.size(); i++)
            m[a[i]]++;
            
        for(auto x: m)
            if(x.second > 1) count += x.second;
            else {
                for(auto y: m)
                    if(x.first <= y.first) break;
                    else if(x.first % y.first == 0) {
                        count++;
                        break;
                    }
            }
        return count;
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
        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}

/* Sample Input:
2
3
2 3 6
4
5 5 5 5

Sample Output:
1
4

*/