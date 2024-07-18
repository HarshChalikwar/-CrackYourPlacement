class Solution {
public:
   void dfs(int sr, int sc , int col1,int col2,vector<vector<int>>& image)
   {
       int m = image.size();
       int n = image[0].size();
       if (sr < 0 || sc < 0 || sr >= m || sc >= n) return;
       if(image[sr][sc] != col2) return;
       image[sr][sc] = col1;
       dfs(sr-1,sc,col1,col2,image);
       dfs(sr,sc-1,col1,col2,image);
       dfs(sr+1,sc,col1,col2,image);
       dfs(sr,sc+1,col1,col2,image);

   }
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int col2 = image[sr][sc];
        if(color != col2) dfs(sr,sc,color,col2,image);
        return image;
    }
};