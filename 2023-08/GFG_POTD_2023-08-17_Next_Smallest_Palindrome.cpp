// GFG POTD 2023/08/17
// Next Smallest Palindrome
// Hard

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGreater(vector<int>& arr, int num[], int n) {
        for(int i = 0; i < n; i++) {
            if(arr[i] < num[i]) return false;
            if(arr[i] > num[i]) return true;
        }
        return false;
    }

    vector<int> generateNextPalindrome(int num[], int n) {
        vector<int> ans(n);
        int l = 0, r = n - 1;
        // For number whose all digits on right are the only ones which are smaller
        while(r > l) {
            ans[r] = ans[l] = num[l];
            l++;
            r--;
        }
        ans[r] = num[r];
        if(isGreater(ans , num , n))
            return ans;

        // For Palindrome number
        int carry = 1;
        if(n % 2 == 1) {
            ans[r]++;
            if(ans[r] < 10)
                return ans;

            ans[r] = 0;
            carry = 1;
            r--;
            l++;
        }
        
        // Changing the digits from the middle
        while(r >= 0) {
            ans[r] += carry;
            ans[l] += carry;
            if(ans[r] < 10)
                return ans;

            ans[r] = ans[l] = 0;
            carry = 1;
            r--;
            l++;
        }

        if(carry == 1) {
            ans.insert(ans.begin() , 1);
            // To handle cases like 9999, 999 to give 10001 , 1001
            ans[ans.size() - 1] = 1;
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
        int num[n];
        for(int i = 0; i < n; i++)
            cin >> num[i];
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for(auto x: ans)
            cout << x << " ";
        cout << endl << endl;
    }
    return 0;
}

/* Sample Input:
6

11
9 4 1 8 7 9 7 8 3 2 2

5
2 3 5 4 5

6
1 2 3 4 5 6

6
6 6 6 6 6 2

5
1 2 3 2 1

17
1 5 3 4 6 7 1 7 4 2 7 3 5 4 7 2 6

Sample Output:
9 4 1 8 8 0 8 8 1 4 9 

2 3 6 3 2 

1 2 4 4 2 1 

6 6 6 6 6 6 

1 2 4 2 1 

1 5 3 4 6 7 1 7 4 7 1 7 6 4 3 5 1 


*/