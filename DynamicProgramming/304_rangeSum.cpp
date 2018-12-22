/*  Range Sum Query 2D - Immutable */
// mutable, segment tree

class NumMatrix
{
  private:
    vector<vector<int>> m_dp;
    int row, col; 

  public:
    NumMatrix(vector<vector<int>> matrix)
    {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        m_dp = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                m_dp[i][j] = matrix[i-1][j-1] + m_dp[i-1][j] + m_dp[i][j-1] - m_dp[i-1][j-1] ;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return m_dp[row2+1][col2+1] - m_dp[row2+1][col1] - m_dp[row1][col2+1] + m_dp[row1][col1];
    }
};
