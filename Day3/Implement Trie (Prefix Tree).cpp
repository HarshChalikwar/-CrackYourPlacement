struct Node{
    public:
    Node* links[26];
    bool flag;
    Node()
    {
        for(int i = 0;i<26;i++)
        {
            links[i] = nullptr;
        }
        flag = false;
    }
    bool checkChar(char k)
    {
        return (links[k-'a'] != nullptr);
    }
    void setChar(char k)
    {
        links[k - 'a'] = new Node();
    }
    Node* getChar(char k)
    {
        return links[k-'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool getEnd(){
        return flag;
    }

};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!node->checkChar(word[i]))
            {
                node->setChar(word[i]);
            }
            node =  node->getChar(word[i]);
        }
        node -> setEnd();
    }
    
    bool search(string word) {
         Node* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!node->checkChar(word[i]))
            {
                return false;
            }
            node =  node->getChar(word[i]);
        }
        return node -> getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0;i<prefix.size();i++)
        {
            if(!node->checkChar(prefix[i]))
            {
                return false;
            }
            node =  node->getChar(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */