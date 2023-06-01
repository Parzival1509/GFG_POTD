// GFG POTD 2023/04/26
// Seating Arrangement
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats) {
        int count = 0;
        for(int i = 0; i < m; i++)
            if(!seats[i] && (i-1 < 0 || seats[i-1] == 0) && (i+1 >= m || seats[i+1] == 0)) {
                count++;
                seats[i] = 1;
            }
        return count >= n;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> seats(m);
        for(int i = 0; i < m; i++)
            cin >> seats[i];
        Solution obj;
        if(obj.is_possible_to_get_seats(n, m, seats))
            cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

/* Sample Input:
2
2
7
0 0 1 0 0 0 1
1
3
0 1 0

Sample Output:
Yes
No

*/