#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};

class Solution{
public:
    bool static cmp(val a1, val a2){
        return a1.first>a2.first;
    }

    int maxChainLen(struct val p[], int n){
        sort(p, p+n, cmp);
        int ans = 1;
        auto prev = p[0];
        for(int i=1; i<n; i++){
            if(p[i].second<prev.first){
                prev = p[i];
                ans++;
            }
        }
        return ans;
    }
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		Solution ob;
		cout<<ob.maxChainLen(p,n)<<endl;
	}
	return 0;
}

/* Sample Input
2 2

Sample Output

*/