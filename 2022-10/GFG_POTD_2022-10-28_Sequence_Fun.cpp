// GFG POTD Sequence Fun

using namespace std;

class Solution {
public:
    const long long m=1e9+7;
    int NthTerm(int n){
        long long ans = 1;
        for(int i=1; i<=n; i++)
            ans = ((ans%m)*i + 1)%m;
        return ans;
    }
};

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        Solution obj;
        int ans = obj.NthTerm(n);
        cout << ans << "\n";
    }
    return 0;
}

/* Sample Input
2
4
10

Sample Output
65
9864101

*/