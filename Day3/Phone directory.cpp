//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
struct Node
{
    public:
    set<string> ind;
    Node* links[26];
    bool flag = false;
    Node()
    {
        for(int i = 0;i<26;i++)
        {
            links[i]=nullptr;
        }
    }
    bool checkKey(char k)
    {
        return (links[k-'a'] != nullptr);
    }
    void setKey(char k)
    {
        links[k-'a'] = new Node();
    }
    Node* getKey(char k)
    {
        return links[k-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};
class trie
{
    public:
    Node* root;
    trie()
    {
        root = new Node();
    }
    void insert(string& word)
    {
        Node* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!node -> checkKey(word[i]))  
            {
                node -> setKey(word[i]);
            }
            node = node -> getKey(word[i]);
            node->ind.insert(word);
        }
        if(!node -> isEnd()) node->ind.insert(word);
        node -> setEnd();
        
    }
    set<string> searchKey(string& word)
    {
        Node* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!node -> checkKey(word[i]))  
            {
                return {};
            }
            node = node -> getKey(word[i]);
        }
        return node->ind;
    }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        
        sort(contact,contact+n);
        vector<vector<string>> ans;
        trie t;
        for(int i = 0;i<n;i++)
        {
            t.insert(contact[i]);
        }
        for(int i = 0;i<s.size();i++)
        {
            string k = s.substr(0,i+1);
            set<string> ans1= t.searchKey(k);
            vector<string> ans2;
            for(auto c:ans1)
            {
                ans2.push_back(c);
            }
            if(ans2.size() == 0) ans.push_back({{"0"}});
            else ans.push_back(ans2);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends