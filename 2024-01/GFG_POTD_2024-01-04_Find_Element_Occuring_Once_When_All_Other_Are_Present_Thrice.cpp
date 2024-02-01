// GFG POTD 2024/01/04
// Find Element Occuring Once When All Other Are Present Thrice
// Medium

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleElement(int arr[], int n) {
        int ans = 0;
        for(int i = 0; i < 32; i++) {
            int odd_ct = 0, even_ct = 0;
            
            for(int j = 0; j < n; j++)
                if(1 << i & arr[j])
                    odd_ct++; // If i'th pos is set or not
                else even_ct++;
            
            if(odd_ct % 3)
                ans |= 1 << i; // Set 1 in i'th pos in ans
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.singleElement(arr, N) << "\n";
    }

    return 0;
}

/* Sample Input:
3
1210
10212
12121

Sample Output:
10
3

*/