// GFG POTD 2022/10/16
// Move Last Element to Front of a Linked List
// Easy

#include <bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int x){
        val=x;
        next=NULL;
    }
};

class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head->next==NULL) return head;
        ListNode *tmp1=head,*tmp2=head->next;
        while(tmp2->next!=NULL){
            tmp1=tmp1->next;
            tmp2=tmp2->next;
        }
        tmp2->next=head;
        tmp1->next=NULL;
        return tmp2;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ListNode*> a(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=new ListNode(x);
            if(i!=0){
                a[i-1]->next=a[i];
            }
        }
        ListNode *head=a[0];
        Solution ob;
        head=ob.moveToFront(head);
        while(head!=NULL){
            cout<<head->val;
            if(head->next!=NULL){
                cout<<" ";
            }
            head=head->next;
        }
        cout<<endl;
    }
    return 0;
}

/* Sample Input
2
1
2
5
2 5 6 2 1

Sample Output
2
1 2 5 6 2

*/