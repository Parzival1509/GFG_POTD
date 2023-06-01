// GFG POTD 2022/12/25
// Missing Number in Matrix
// Easy

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// bool rows(vector<vector<int>> mat, int n) {
	// 	long long r1=0;
	// 	for(int i=0; i<n; i++)
	// 		r1 += mat[0][i];
	// 	for(int i=1; i<n; i++) {
	// 		long long s=0;
	// 		for(int j=0; j<n; j++)
	// 			s += mat[i][j];
	// 		if(s != r1) return false;
	// 	}
	// 	return true;
	// }

	// bool cols(vector<vector<int>> mat, int n) {
	// 	long long c1=0;
	// 	for(int i=0; i<n; i++)
	// 		c1 += mat[i][0];
	// 	for(int i=1; i<n; i++) {
	// 		long long s=0;
	// 		for(int j=0; j<n; j++)
	// 			s += mat[j][i];
	// 		if(s != c1) return false;
	// 	}
	// 	return true;
	// }

 //    long long MissingNo(vector<vector<int>>& mat) {
 //        long long sum=0, d1=0, d2=0;
 //        int n = mat.size();

 //        // Finding the position of the 0 and sum of diagonals
 //       	int r, c;
 //       	for(int i=0; i<n; i++)
 //       		for(int j=0; j<n; j++)
 //       			if(mat[i][j] == 0) {
 //       				r=i;
 //       				c=j;
 //       			}

 //       	// Finding the difference in sums
 //       	if(r==0) {
 //       		for(int i=0; i<n; i++)
 //       			sum += mat[1][i]-mat[0][i];
 //       		mat[r][c] = sum;
 //       	}
 //       	else {
 //       		for(int i=0; i<n; i++)
 //       			sum += mat[0][i]-mat[r][i];
 //       		mat[r][c] = sum;
 //       	}

 //       	// Finding sum of Diagonals
 //       	for(int i=0; i<n; i++) {
 //       		d1 += mat[i][i];
 //       		d2 += mat[i][n-1-i];
 //       	}

 //       	if(rows(mat, n) && cols(mat, n) && d1==d2 && sum>0)
 //       		return sum;
 //       	return -1;
 //    }

    bool row(vector<vector<int>>& a, int n){
        int r1=0;
        for(int i=0; i<n; i++)
            r1 += a[0][i];
        for(int i=1; i<n; i++){
            int r=0;
            for(int j=0; j<n; j++)
                r += a[i][j];
            if(r != r1)
                return false;
        }
        return true;
    }
    
    bool col(vector<vector<int>>& a, int n){
        int c1=0;
        for(int i=0; i<n; i++)
            c1 += a[i][0];
        for(int i=1; i<n; i++){
            int c=0;
            for(int j=0; j<n; j++)
                c += a[j][i];
            if(c != c1)
                return false;
        }
        return true;
    }
    
    bool dia(vector<vector<int>>& a, int n){
        int d1=0, d2=0;
        for(int i=0; i<n; i++)
            d1 += a[i][n-1-i];
        for(int i=0;i<n;i++)
            d2 += a[i][i];
        return (d1==d2);
    }
    
    long long MissingNo(vector<vector<int>>& a) {
        long long ans=0, r, c;
        int n = a.size();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(a[i][j] == 0){
                    r = i;
                    c = j;
                }
        if(r==0){
            for(int i=0; i<n; i++)
                ans += a[1][i]-a[0][i];
            a[r][c] = ans;
        }
        else{
            for(int i=0; i<n; i++)
                ans += a[0][i]-a[r][i];
            a[r][c] = ans;
        }
        if(row(a, n) && col(a, n) && dia(a, n) && ans>0)
            return ans;
        return -1;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		Solution ob;
		long long ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}

/* Sample Input
5
2
5 5
5 0
3
1 2 0
3 1 2
2 3 1
3
4 0 2
3 5 7
8 1 6
3
3 8 1
2 4 6
7 0 5
7
250000000 1000000000 1000000000 250000000 1000000000 1000000000 250000000
1000000000 250000000 1000000000 250000000 1000000000 250000000 1000000000
1000000000 1000000000 250000000 250000000 250000000 1000000000 1000000000
250000000 250000000 250000000 0 250000000 250000000 250000000
1000000000 1000000000 250000000 250000000 250000000 1000000000 1000000000
1000000000 250000000 1000000000 250000000 1000000000 250000000 1000000000
250000000 1000000000 1000000000 250000000 1000000000 1000000000 250000000
Sample Output
5
-1
9
-1
3250000000

*/