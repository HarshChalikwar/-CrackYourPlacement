class Solution {
public:
    struct Node {
        int ind;
        Node* links[26];
        vector<int> list;
        Node() {
            ind = -1;
            for (int i = 0; i < 26; i++) links[i] = nullptr;
        }
        bool checkKey(char k) {
            return (links[k - 'a'] != nullptr);
        }
        Node* getKey(char k) {
            return links[k - 'a'];
        }
        void setKey(char k) {
            links[k - 'a'] = new Node();
        }
        void setEnd(int k) {
            ind = k;
        }
        int isEnd() {
            return ind;
        }
    };

    class Trie {
    public:
        Node* root;
        Trie() {
            root = new Node();
        }
        void insertKey(string& word, int j) {
            Node* node = root;
            for (int i = word.size() - 1; i >= 0; i--) {
                if (!node->checkKey(word[i])) node->setKey(word[i]);
                node = node->getKey(word[i]);
                if (isPalindrome(word, 0, i-1)) {
                    node->list.push_back(j);
                }
            }
            node->setEnd(j);
        }
        bool isPalindrome(string& s, int i, int j) {
            if(i == j) return true;
            while (i < j) {
                if (s[i++] != s[j--]) return false;
            }
            return true;
        }
        void searchKey(vector<string>& words, int i, vector<vector<int>>& res) {
            if(words[i].size() == 0)
            {
                for(int j = 0;j<words.size();j++)
                {
                    if( j != i and isPalindrome(words[j],0,words[j].size()-1))
                    {
                        res.push_back({i,j});
                    }
                }
            }
            Node* node = root;
            for (int j = 0; j < words[i].size(); j++) {
                if (node->isEnd() >= 0 && node->isEnd() != i && isPalindrome(words[i], j, words[i].size() - 1)) {
                    res.push_back({i, node->isEnd()});
                }
                if (!node->checkKey(words[i][j])) return;
                node = node->getKey(words[i][j]);
            }
            for (int j : node->list) {
                if (i == j) continue;
                res.push_back({i, j});
            }
        }
    };

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ans;
        Trie t;
        for (int i = 0; i < words.size(); i++) {
            t.insertKey(words[i], i);
        }
        for (int i = 0; i < words.size(); i++) {
            t.searchKey(words, i, ans);
        }
        return ans;
    }
};