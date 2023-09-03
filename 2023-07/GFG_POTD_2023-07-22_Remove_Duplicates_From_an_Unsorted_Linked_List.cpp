// GFG POTD 2023/07/22
// Remove Duplicates From an Unsorted Linked List
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

class Solution {
public:
    Node* removeDuplicates(Node* head)  {
        vector<int> hsh(10001, 0);
        Node* tmp = head;
        hsh[tmp->data]++;
        
        while(tmp->next != NULL) {
            if(hsh[tmp->next->data]++)
                tmp->next = tmp->next->next;
            else
                tmp = tmp->next;
        }
        
        return head;
    }
};

int main() {
    int T;
    cin>>T;
    while(T--) {
        int K;
        cin >> K;
        Node *head = NULL;
        Node *temp = head;
 
        for(int i = 0; i < K; i++) {
            int data;
            cin >> data;
            if(head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}

/* Sample Input:
2
4
5 2 2 4
5
2 2 2 2 2

Sample Output:
5 2 4 
2 

*/