// GFG POTD 2023/08/14
// Non Repeating Numbers
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int> nums) {
        int n = nums.size(), ans = 0, x = 0, y = 0;
        for(int i = 0; i < n; i++)
            ans ^= nums[i];
        
        int rightMostSetBit = ans & ~(ans - 1);
        
        for(int i = 0; i < n; i++)
            if(nums[i] & rightMostSetBit)
                x ^= nums[i];
            else y ^= nums[i];
        
        vector<int> v(2);
        if(x > y) swap(x, y);
        v[0] = x, v[1] = y;
        
        return v;
    }
};

int main(){
    int T;
    cin >> T;
    while(T--) {
        int n; 
        cin >> n;
        vector<int> v(2 * n + 2);
        for(int i = 0; i < 2 * n + 2; i++)
            cin >> v[i];
        Solution ob;
        vector<int > ans = ob.singleNumber(v);
        for(auto i: ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
2
1 2 3 2 1 4
1
2 1 3 2

Sample Output:
3 4 
1 3 

*/