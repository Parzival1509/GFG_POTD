// GFG POTD 2024/07/02
// Linked List of Strings Forms a Palindrome
// Easy

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string data;
    Node* next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};

Node* newNode(string str) {
    Node* new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

void print(Node* root) {
    Node* temp = root;

    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

class Solution {
public:
    bool palindromeCheck(string str) {
        int l = str.length();
        for (int i = 0; i < l / 2; i++)
            if (str[i] != str[l - i - 1])
                return false;

        return true;
    }

    bool compute(Node* head) {
        string s = "";
        while (head != NULL) {
            s.append(head->data);
            head = head->next;
        }

        return palindromeCheck(s);
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        struct Node* head = NULL;
        struct Node* temp = head;

        for (int i = 0; i < K; i++) {
            string str = "";
            cin >> str;
            if (head == NULL)
                head = temp = new Node(str);
            else {
                temp->next = new Node(str);
                temp = temp->next;
            }
        }
        Solution ob;
        bool ans = ob.compute(head);
        if (ans)
            cout << "true" << endl;
        else cout << "false" << endl;
    }
    
    return 0;
}

/* Sample Input
3
4
b eeee b b
5
a bc d dcb a
4
a bc d ba

Sample Output
false
true
false

*/