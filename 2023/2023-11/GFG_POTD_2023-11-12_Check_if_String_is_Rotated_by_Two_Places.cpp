// GFG POTD 2023/11/12
// Check if String is Rotated by Two Places
// Easy

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRotated(string a, string b) {
        int n = a.size();
        if(n != b.size()) return false;
        
        bool left = true, right = true;
        
        // // Approach 1: Using extra space, S.C. = O(N)
        // string ta(n, ' '), tb(n, ' ');
        
        // for(int i = 0; i < n; i++) {
        //     ta[(i + 2) % n] = a[i];
        //     tb[(i - 2 + n) % n] = a[i];
        // }
       
        // for(int i = 0; i < n; i++) {
        //     if(b[i] != ta[i])
        //         right = false;
        //     if(b[i] != tb[i])
        //         left = false;
        
        //     if(!left && !right) return false;
        // }
        
        // Approach 2: Without using extra space, S.C. = O(1)
        for(int i = 0; i < n; i++) {
            if(a[(i + 2) % n] != b[i])
                right = false;
            if(a[(i - 2 + n) % n] != b[i])
                left = false;
                
            if(!left && !right) return false;
        }
        
        return true;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        Solution obj;
        cout << obj.isRotated(a, b)<<endl;
    }
    return 0;
}

/* Sample Input:
2
amazon azonam
geeksforgeeks geeksgeeksfor

Sample Output:
1
0

*/