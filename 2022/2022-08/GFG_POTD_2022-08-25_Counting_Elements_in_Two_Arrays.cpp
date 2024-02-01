//GFG POTD Counting Elements in Two Arrays
#include<bits/stdc++.h>
using namespace std;

int start_up(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
int static r = start_up();

class Solution{
public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n){
        sort(arr2, arr2+n);
        vector<int> ans;
        for(int i=0; i<m; i++){
            int l=0, r=n-1, mid;
            while(l<=r){
                mid = (l+r)/2;
                if(arr2[mid] > arr1[i]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if(arr2[mid] <= arr1[i])
                ans.push_back(mid+1);
            else
                ans.push_back(mid);
        }
        return ans;
    }
};

int main(){
    Solution ob;
    int m, n;
    cin>>m>>n;
    int arr1[m], arr2[n];
    for(int i=0; i<m; i++)
        cin>>arr1[i];
    for(int i=0; i<n; i++)
        cin>>arr2[i];
    vector<int> ans = ob.countEleLessThanOrEqual(arr1, arr2, m, n);
    for(int i=0; i<m; i++)
        cout<<ans[i]<<' ';
    cout<<endl;
    return 0;
}

/* Sample Input
6 6
1 2 3 4 7 9
0 1 2 1 1 4

Sample Output
4 5 5 6 6 6 

*/