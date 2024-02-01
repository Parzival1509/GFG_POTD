#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        int ans=0;
        while(!pq.empty() && pq.top()<k){
            int first=pq.top();
            pq.pop();
            int second=0;
            if(!pq.empty()){
                second=pq.top();
                pq.pop();
            }
            
            pq.push(first+second);
            ans++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}