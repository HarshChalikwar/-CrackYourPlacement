class NumMatrix {
public:
    vector<vector<int>> matrix;
    vector<vector<long long>> dp1;
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        dp1.resize(matrix.size(),vector<long long>(matrix[0].size(),0));
        long long sum = 0;
        for(int i = 0;i<matrix.size();i++)
        {
            sum = 0;
            for(int j = 0;j<matrix[0].size();j++)
            {
                sum+= matrix[i][j];
                if(i == 0)
                dp1[i][j] = sum;
                else
                dp1[i][j] = sum + dp1[i-1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        long long ans = 0;
        ans += dp1[row2][col2];
        if(row1 > 0) ans -= dp1[row1-1][col2];
        if(col1 > 0) ans -= dp1[row2][col1-1];
        if(row1 > 0 and col1> 0) ans+= dp1[row1-1][col1-1];
        return (int)ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */