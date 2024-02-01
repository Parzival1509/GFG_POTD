// GFG POTD Phone Directory

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s){
        vector<vector<string>> ans;
        vector<string> tmp;
        int l=0, h=n-1;
        // Sorting the contacts
        for(int i=0; i<n; i++)
            tmp.push_back(contact[i]);
        sort(tmp.begin(), tmp.end());

        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            vector<string> t;

            // Lower search limit
            int hh=h, ll=l, a=-1, b=-1;
            while(hh-ll>1){
                int mid = (hh-ll)/2 + ll;
                if(tmp[mid][i] > ch)
                    hh=mid-1;
                else if(tmp[mid][i] < ch)
                    ll=mid+1;
                else
                    hh=mid;
            }
            if(tmp[ll][i]==ch)
                a=ll;
            else if(tmp[hh][i]==ch)
                a=hh;

            // Upper search limit
            hh=h; ll=l;
            while(hh-ll>1){
                int mid = (hh-ll)/2 + ll;
                if(tmp[mid][i] > ch)
                    hh=mid-1;
                else if(tmp[mid][i] < ch)
                    ll=mid+1;
                else
                    ll=mid;
            }
            if(tmp[hh][i]==ch)
                b=hh;
            else if(tmp[ll][i]==ch)
                b=ll;
            // cout<<a<<' '<<b<<' '<<endl;

            // Pushing the contacts mathching the prefix in a vector
            if(b>=a and a!=-1 and b!=-1){
                vector<string> t;
                set<string> st;
                for(int j=a; j<=b; j++)
                    st.insert(tmp[j]);
                for(auto el: st)
                    t.push_back(el);
                ans.push_back(t);
                l=a; h=b;
            }
            else
                break;
        }
        for(int i=ans.size(); i<s.size(); i++){
            vector<string> v;
            v.push_back("0");
            ans.push_back(v);
        }
        return ans;

        // Brute-Force approach (Shows TLE)
        // // Finding the matching contacts with the first letter of s as prefix
        // auto it=tmp.begin();
        // while(it != tmp.end()){
        //     string cur = *it;
        //     if(cur[0] != s[0])
        //         tmp.erase(it);
        //     else
        //         it++;
        // }

        // if(tmp.size()!=0)
        //     ans.push_back(tmp);
        // else{
        //     vector<vector<string>> res(s.size(), vector<string> (1, "0"));
        //     return res;
        // }

        // // Finding the matching contacts for the other prefixes
        // for(int i=1; i<s.size(); i++){
        //     it=tmp.begin();
        //     while(it != tmp.end()){
        //         string cur = *it;
        //         if(cur.find(s.substr(0, i+1), 0) == string::npos)
        //             tmp.erase(it);
        //     }
        //     if(tmp.size()!=0)
        //         ans.push_back(tmp);
        //     else{
        //         for(; i<s.size(); i++){
        //             vector<string> t(1, "0");
        //             ans.push_back(t);
        //         }
        //         return ans;
        //     }
        // }
        // return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i=0; i<n; i++)
            cin>>contact[i];
        cin>>s;
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i=0; i<s.size(); i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

/* Sample Input
4
3
geeikistest geeksforgeeks geeksfortest
geeips
6
abxthtnpwcxgdh abnmjywmfznpmfdsq abfhztcgppxnru abvbpkqyimkpmzhaekuxgdwc abftvcgoxbjasvqqddctrbat abkoettbxzgsuiak
abfdld
10
abznehvggnuadsko abdnhtuydwvvh abqljekyiuvqajk abocnecsrlmnkp abhmtxfejjrhtldl abovqcafic abzqmnabyjprhuwqfnz abaclpshgwjnenlgdxtfa abpqjymhouwpswuelmntjy abpluvrsow
aboikd
11
saniehbjjchgeec sanjeaifaeei sanbccihgeigi sanhijjfidbabc sancaceggcd saneghdcdeidcfd sanhajc sanaedh sangbcehhiidgh saniadifffjie sanijbafgjfeahj
sanjej


Sample Output
geeikistest geeksforgeeks geeksfortest 
geeikistest geeksforgeeks geeksfortest 
geeikistest geeksforgeeks geeksfortest 
geeikistest 
0 
0 
abfhztcgppxnru abftvcgoxbjasvqqddctrbat abkoettbxzgsuiak abnmjywmfznpmfdsq abvbpkqyimkpmzhaekuxgdwc abxthtnpwcxgdh 
abfhztcgppxnru abftvcgoxbjasvqqddctrbat abkoettbxzgsuiak abnmjywmfznpmfdsq abvbpkqyimkpmzhaekuxgdwc abxthtnpwcxgdh 
abfhztcgppxnru abftvcgoxbjasvqqddctrbat 
0 
0 
0 
abaclpshgwjnenlgdxtfa abdnhtuydwvvh abhmtxfejjrhtldl abocnecsrlmnkp abovqcafic abpluvrsow abpqjymhouwpswuelmntjy abqljekyiuvqajk abznehvggnuadsko abzqmnabyjprhuwqfnz 
abaclpshgwjnenlgdxtfa abdnhtuydwvvh abhmtxfejjrhtldl abocnecsrlmnkp abovqcafic abpluvrsow abpqjymhouwpswuelmntjy abqljekyiuvqajk abznehvggnuadsko abzqmnabyjprhuwqfnz 
abocnecsrlmnkp abovqcafic 
0 
0 
0 
sanaedh sanbccihgeigi sancaceggcd saneghdcdeidcfd sangbcehhiidgh sanhajc sanhijjfidbabc saniadifffjie saniehbjjchgeec sanijbafgjfeahj sanjeaifaeei 
sanaedh sanbccihgeigi sancaceggcd saneghdcdeidcfd sangbcehhiidgh sanhajc sanhijjfidbabc saniadifffjie saniehbjjchgeec sanijbafgjfeahj sanjeaifaeei 
sanaedh sanbccihgeigi sancaceggcd saneghdcdeidcfd sangbcehhiidgh sanhajc sanhijjfidbabc saniadifffjie saniehbjjchgeec sanijbafgjfeahj sanjeaifaeei 
sanjeaifaeei 
sanjeaifaeei 
0 

*/