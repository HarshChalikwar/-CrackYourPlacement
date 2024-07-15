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
    bool getEnd()
    {
        return flag;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() 
    {
        root = new Node();
    }
    void addWord(string word) {
        Node* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!node -> checkKey(word[i]))
            {
                node -> setKey(word[i]);
            }
            node = node -> getKey(word[i]);
        }
        node -> setEnd();
    }
    bool searchword(Node* node,int i,string word)
    {
        if(i == word.size())
        {
            return node -> getEnd();
        }
        else if(word[i] == '.')
        {
            bool ans = false;
            for(char j = 'a';j<='z';j++)
            {
                if(node -> checkKey(j))
                {
                    ans = ans or searchword(node->getKey(j),i+1,word);
                }
            }
            return ans;
        }
        else
        {
            if(node -> checkKey(word[i]))
            {
                return searchword(node->getKey(word[i]),i+1,word);
            }
            else return false;
        }
    }
    bool search(string word) {
        return searchword(root,0,word);
    }
};