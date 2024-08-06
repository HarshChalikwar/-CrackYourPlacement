class Solution {
public:
    bool isValid(int i,int j,int n,int m)
    {
        if(i<n and j<m and i>=0 and j>=0) return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                int x[] = {0,0,1,-1,1,1,-1,-1};
                int y[] = {1,-1,0,0,1,-1,-1,1};
                int live = 0;
                for(int k = 0;k<8;k++)
                {
                    int i_n = i+x[k];
                    int j_n = j+y[k];
                    if(isValid(i_n,j_n,board.size(),board[0].size()))
                    {
                        if(board[i_n][j_n] == 1 or board[i_n][j_n] == -1) live++;
                    }
                }   
                if((live < 2 or live >3) and board[i][j] == 1) board[i][j] = -1;
                else if((live == 2 or live == 3) and (board[i][j] == 1)) continue;
                else if(live == 3 and board[i][j] == 0) board[i][j] = -2;
            }
        }
        for(int i = 0;i<board.size();i++)
        {
            for(int j = 0;j<board[0].size();j++)
            {
                if(board[i][j] == -1) board[i][j] = 0;
                else if(board[i][j] == -2) board[i][j] = 1;
            }
        }
    }
};