// GFG POTD 2022/11/13
// Fill Up Buckets

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    const int m=1e9+7;
    int totalWays(int n, vector<int> capacity) {
        sort(capacity.begin(), capacity.end());
        long long ans=capacity[0];
        // cout<<ans<<" * ";
        for(int i=1; i<capacity.size(); i++){
            // cout<< capacity[i]-i<<" * ";
            ans = ((capacity[i]-i)*ans)%m;
        }
        // cout<<endl;
        return ans;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        vector<int>capacity(n);
        for(int i = 0; i < n; i++)
            cin >> capacity[i];
        Solution ob;
        int ans = ob.totalWays(n, capacity);
        cout << ans << "\n";
    }  
    return 0;
}

/* Sample Input
4
1
6
2
5 8
7
13 10 10 7 7 3 7
118
2 4 8 11 15 15 16 17 18 23 24 28 29 30 32 32 33 36 36 38 43 43 47 49 50 52 53 55 55 56 60 61 62 64 66 68 69 71 71 71 74 75 75 75 78 79 79 81 83 83 84 84 85 86 86 87 93 93 97 100 100 106 107 108 109 111 111 112 113 114 120 123 123 129 129 134 135 135 140 140 142 143 143 144 147 147 148 148 149 151 152 153 153 156 157 158 159 160 161 162 165 165 171 174 175 176 177 179 180 183 184 184 187 189 192 193 194 197 


Sample Output
6
35
75600
644117864

*/