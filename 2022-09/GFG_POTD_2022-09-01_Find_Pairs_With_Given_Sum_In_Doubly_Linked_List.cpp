// GFG POTD Find pairs with given sum in doubly linked list
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL){
    }
};

class Solution
{
public:
    vector<int> arr;
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
        vector<pair<int,int>> ans;
        Node* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp=temp->next;
        }
        int l=0,r=arr.size()-1;
        while(l<r){
            if(arr[l]+arr[r]>target)
            r--;
            else if(arr[l]+arr[r]<target)
            l++;
            else{
            ans.push_back({arr[l],arr[r]});
            l++;
            }
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--){
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++){
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
        cout << "\n";
    }
    return 0;
}