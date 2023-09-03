// GFG POTD 2023/06/22
// Lemonade Change
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(int n, vector<int> &bills) {
        int fives = 0, tens = 0;
        for(int i = 0; i < n; i++) {
            if(bills[i] == 5) fives++;
            else if(bills[i] == 10) {
                tens++;
                fives--;
                if(fives < 0) return false;
            }
            else {
                if(tens > 0 && fives > 0) {
                    tens--;
                    fives--;
                }
                else if(fives > 2) fives -= 3;
                else return false;
            }
        }
        
        return true;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> bills(n);
        for(int i = 0; i < n; i++)
            cin >> bills[i];
        Solution obj;
        int ans = obj.lemonadeChange(n, bills);
        if(ans) cout << "True" << endl;
        else cout << "False" << endl;
    }
    return 0;
}

/* Sample Input:
4
5
5 5 5 10 20
5
5 5 10 10 20
8
5 5 5 20 5 10 10 5
9
5 10 5 10 5 5 5 10 5

Sample Output:
True
False
False
True

*/