// GFG POTD 2024/02/04
// Subtraction in Linked List
// Hard

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};

class Solution {
public:
    LinkedList obj = LinkedList();
    
    int length(Node* head) {
        int len = 0;
        while(head != NULL) {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
    Node* rev(Node* head) {
        if(head == NULL) return 0;
        
        Node* left = NULL;
        Node* right = NULL;
        while(head) {
            right = head->next;
            head->next = left;
            left = head;
            head = right;
        }
        
        return left;
    }
    
    Node* sub(Node* head1, Node* head2)   {
        if(head1 == NULL && head2 == NULL) {
            obj.insert(0);
            return obj.head;
        }
        
        if(head1 == NULL || head2 == NULL)  {
            Node* ans = rev(head1);
            while(ans && ans->data == 0)
                ans = ans->next;
            
            return ans;
        }
        
        bool c = false;
        while(head2) {
            if(c) head1->data -= 1;
            if(head1->data < head2->data) {
                c = true;
                head1->data += 10;
            }
            else c = false;
            int ans = head1->data - head2->data;
            obj.insert(ans);
            head1 = head1->next;
            head2 = head2->next;
        }
        
        while(head1) {
            if(c) head1->data -= 1;
            if(head1->data < 0) {
                c = true;
                head1->data += 10;
            }
            else c = false;
            int ans = head1->data;
            obj.insert(ans);
            head1 = head1->next;
        }
        
        Node* ans = rev(obj.head);
        while(ans && ans->data==0)
            ans = ans->next;
        
        return ans;
    }
    
    Node* subLinkedList(Node* head1, Node* head2)  {
        while(head1 && head1->data == 0)
            head1 = head1->next;
        while(head2 && head2->data == 0)
            head2 = head2->next;
    
        int l1 = length(head1), l2 = length(head2);
        bool flag = true;
        
        if(l1 > l2) flag = true;
        else if(l1 == l2) {
            Node* t1 = head1;
            Node* t2 = head2;
            while(t1 && t2 && t1->data == t2->data) {
                t1 = t1->next;
                t2 = t2->next;
            }
            if(t1 && t2)
                flag = (t1->data >= t2->data);
        }
        else flag = false;
        
        head1 = rev(head1);
        head2 = rev(head2);
        
        Node* ans = NULL;
        
        if(flag) ans = sub(head1, head2);
        else ans = sub(head2, head1);
        
        if(ans == NULL) 
            ans = new Node(0);
        
        return ans;
    }
};

void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1, l2;
        cin >> l1;
        for (int j = 0; j < n; ++j) {
            int x = (l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin >> l2;
        for (int j = 0; j < m; ++j) {
            int x = (l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

/* Sample Input:
2
3 100
2 12
4 0063
3 710

Sample Output:
88
647

*/