class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<n and j<m and i>=0 and j>=0 ) return true;
        return false;
    }
    bool rec(vector<vector<char>>& board,vector<vector<int>>& vis,string& word,int k,int i,int j)
    {
        if(k == word.size()) return true;
        int x[] = {0,0,-1,1};
        int y[] = {-1,1,0,0};
        vis[i][j] = 1;
        bool ans = false;
        for(int m = 0;m<4;m++)
        {
            int i_n = i + x[m];
            int j_n = j + y[m];
            if(isValid(i_n,j_n,board.size(),board[0].size()) and !vis[i_n][j_n])
            {
                if(board[i_n][j_n] == word[k] )
                { 
                    ans  = ans or rec(board,vis,word,k+1,i_n,j_n);
                    if(ans) return true;
                }
            }
        }
        vis[i][j] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>&  board, string word) {
        bool ans = false;
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
                    ans = ans or rec(board,vis,word,1,i,j);
                    if(ans) return true;
                }
            }
        }
        return ans;
    }
};