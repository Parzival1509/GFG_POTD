// GFG POTD 2023/04/21
// Prefix Suffix String
// Medium

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    class TrieNode {
    public:
        bool isEndOfWord;
        TrieNode* children[26];
        
        TrieNode() {
            isEndOfWord = false;
            for(int i=0; i<26; i++)
                children[i] = NULL;
        }

        void insert(string s1, TrieNode* root) {
            TrieNode* cur = root;
            for(int i=0; i<s1.length(); i++) {
                int index = s1[i]-'a';
                if(cur->children[index] == NULL)
                    cur->children[index] = new TrieNode();
                cur = cur->children[index];
            }
            cur->isEndOfWord = true;
        }

        bool search(string s1, TrieNode* root) {
            TrieNode* cur = root;
            for(int i=0; i<s1.length(); i++) {
                int index = s1[i]-'a';
                if(cur->children[index] == NULL)
                    return false;
                cur = cur->children[index];
            }
            return true;
        }
    };
    
    int prefixSuffixString(vector<string> &s1,vector<string> s2) {
        TrieNode* root = new TrieNode();
        
        for(int i=0; i<s1.size(); i++) {
            root->insert(s1[i], root);
            reverse(s1[i].begin(), s1[i].end());
            root->insert(s1[i], root);
        }

        int ans = 0;
        for(int i=0; i<s2.size(); i++) {
            string rev=s2[i];
            reverse(rev.begin(), rev.end());
                if(root->search(s2[i], root) || root->search(rev, root))
                    ans++;
            }
        return ans;
    }

    // // 
    // int prefixSuffixString(vector<string> &s1, vector<string> s2) {
    //     int ans = 0;
    //     for(auto c: s2) {
    //         int size = c.size();
    //         for(auto child : s1) {
    //             int n = child.size();
    //             if(n < size) continue;
    //             if(c[0] == child[0]) {
    //                 string left = child.substr(0,size);
    //                 if(left == c) {
    //                     ans++;
    //                     break;
    //                 }
    //             }
    //             if(c[size-1] == child[n-1]) {
    //                 string right = child.substr(n-size, size);
    //                 if(right == c) {
    //                     ans++;
    //                     break;
    //                 }
    //             }
    //         }
    //     }
    //     return ans;
    // }
};

int main() {
    int t;
    cin>>t;
    for(int i=0; i<t; i++) {
        string str1, str2, newline;
        if(i == 0)
        getline(cin, newline);
        getline(cin, str1);
        getline(cin, str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1, s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str)
            s1.push_back(str);
        while(ss2>>str)
            s2.push_back(str);
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}

/* Sample Input:
2
cat catanddog lion
cat dog rat
jrjiml tchetn ucrhye ynayhy cuhffd cvgpoiu znyadv
jr ml cvgpoi gpoiu wnmkmluc geheqe uglxagyl uyxdroj

Sample Output:
2
4

*/