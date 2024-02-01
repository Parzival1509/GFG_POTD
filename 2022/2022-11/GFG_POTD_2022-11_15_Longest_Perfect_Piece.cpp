// GFG POTD 2022/11/15
// Longest Perfect Piece

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPerfectPiece(int a[], int n) {
        int l=0, h=0, ans=0;
        map<int, int> mp;
        while(h<n) {
            mp[a[h]]++;
            while((--mp.end())->first - mp.begin()->first > 1) {
                mp[a[l]]--;
                if(mp[a[l]]==0)
                    mp.erase(a[l]);
                l++;
            }
            ans=max(ans, h-l+1);
            h++;
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}

/* Sample Input
2
4
8 8 8 8
11
5 4 5 5 6 7 8 8 8 7 6

Sample Output
4
5

*/