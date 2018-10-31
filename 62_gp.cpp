class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 0 || n <= 0)
            return 0; 
        
        if(m < n){
            // row < cols
            vector<int> dp(m, 1);
            for(int c = 1; c < n ; c++){
                for(int r = 1; r < m; r++){
                    dp[r] = dp[r - 1] + dp[r];
                }
            }
            return dp[m-1];
        }else{
            // row > cols
            vector<int> dp(n, 1);
            for(int c = 1; c < m ; c++){
                for(int r = 1; r < n; r++){
                    dp[r] = dp[r - 1] + dp[r];
                }
            }
            return dp[n-1];
        }  
    }
};