// GFG POTD 2024/01/18
// Water the Plants
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int min_sprinklers(int gallery[], int n) {
        vector<int> plant(n, -1);
        for(int i = 0; i < n; i++)
            if(gallery[i] != -1) {
                int a = max(0, i - gallery[i]);
                int b = min(n - 1, i + gallery[i]);
                for(int j = a; j <= b; j++)
                    plant[j] = max(plant[j], b);
            }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(plant[i] == -1)
                return -1;
            
            if(i <= plant[i]) {
                ans++;
                i = plant[i];
            }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int gallery[n];
        for(int i = 0; i < n; i++)
            cin >> gallery[i];
        Solution obj;
        cout << obj.min_sprinklers(gallery, n) << endl;
    }

    return 1;
}

/* Sample Input:
4
6
-1 2 2 -1 0 0
8
1 0 4 2 0 6 2 4
9
2 3 4 -1 2 0 0 -1 0
9
2 3 4 -1 0 0 0 0 0

Sample Output:
2
1
-1
3

*/