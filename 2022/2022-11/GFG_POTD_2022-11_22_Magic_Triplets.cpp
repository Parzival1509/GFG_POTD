// GFG POTD 2022/11/22
// Magic Triplets

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int countTriplets(vector<int>a){
        int ans=0, n=a.size();
        for(int i=0; i<n; i++){
            int left=0, right=0;
            // no. smaller than a[i] would be in the left 
            for(int j=i-1; j>=0; j--)
                if(a[i]>a[j]) left++;
             // no. larger than a[i] would be int the right 
             for(int k=i+1; k<n; k++)
                 if(a[i]<a[k]) right++;
             ans += left*right;
        }
        return ans;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>nums(n);
        for(int i = 0; i < n; i++)cin >> nums[i];
        Solution ob;
        int ans = ob.countTriplets(nums);
        cout << ans << "\n";
    }  
    return 0;
}

/* Sample Input
2
3
3 2 1
4
1 2 3 4

Sample Output
0
4

*/