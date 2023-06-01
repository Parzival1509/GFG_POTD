// GFG POTD The Smurfs

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findMin(int n, char a[]){
        int r=0, g=0, b=0;
        for(int i=0; i<n; i++){
            if(a[i]=='R')
                r++;
            else if(a[i]=='G')
                g++;
            else
                b++;
        }
        if(r==g && g==b)
            return 2;
        else if((r==0 && g==0) || (g==0 && b==0) || (b==0 && r==0))
            return n;
        else if(r%2==0 && g%2==0 && b%2==0)
            return 2;
        else if(r%2!=0 && g%2!=0 && b%2!=0)
            return 2;
        else 
            return 1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}

/* Sample Input
2
5
R G B R B
2
R R

Sample Output
1
2

*/