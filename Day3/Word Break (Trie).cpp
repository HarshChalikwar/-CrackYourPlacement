//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    struct Node{
        public: 
        Node* links[26];
        bool flag;
        Node()
        {
            flag = false;
            for(int i = 0;i<26;i++)
            {
                links[i] = nullptr;
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
    class Trie
    {
        public:
        Node* root;
        Trie()
        {
            root = new Node();
        }
        void insertWord(string k)
        {
            Node* node = root;
            for(int i = 0;i<k.size();i++)
            {
                if(!node -> checkKey(k[i]))
                {
                    node -> setKey(k[i]);
                }
                node = node -> getKey(k[i]);
            }
            node -> setEnd();
        }
        bool searchWord(string A,Node* node,int i)
        {
            if(i == A.size()) 
            {
                return node -> isEnd();
            }
            int ans  = false;
            if(node -> isEnd())
            {
                ans = ans or searchWord(A,root,i);
            }
            if(node -> checkKey(A[i]))
            {
                ans = ans or searchWord(A,node -> getKey(A[i]),i+1);
            }
            return ans;
        }
        bool search(string A)
        {
            return searchWord(A,root,0);
        }
        
    };
    int wordBreak(string A, vector<string> &B) {
        //code here
        Trie trie;
        for(int i = 0;i<B.size();i++)
        {
            trie.insertWord(B[i]);
        }
        if(trie.search(A)) return 1;
        return 0;
        
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends