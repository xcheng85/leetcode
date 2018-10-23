class Solution {
public:
bool canWinNim(int n) {
return ((n % 4) != 0);
}
};

class Solution {
public:
    bool canWinNim(int n) {
        if(n <= 3){
            return true; 
        }
        
        vector<bool> dp(3, false); 
        
        dp[0] = dp[1] = dp[2] = true; 
        
        for(int i = 4; i <= n; i++){
            bool tmp = (!dp[0]) || (!dp[1]) || !(dp[2]) ;
            dp[0] = dp[1]; 
            dp[1] = dp[2]; 
            dp[2] = tmp; 
        }
        
        return dp[2]; 
    }
};