#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    vector<int> v = {1,1,2,6,24,120,720,5040,40320,362880};
	    vector<int> ans;
	    int i=9;
	    while(N>0)
	    {
	        if(N >= v[i])
	        {
	            int cnt = N/v[i];
	            ans.insert(ans.end(),cnt,i);
	            N%=v[i];
	        }
	        i--;
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.FactDigit(N);
		for(auto i: ans)
			cout << i;
		cout << "\n";
	}  
	return 0;
}