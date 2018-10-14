class Solution {
public:
// classic dp 1d 
    int maxSubArray(vector<int>& nums) {
        vector<int> dp; 
        dp.resize(nums.size(), 0);
        dp[0] = nums[0];
        int maxv = dp[0]; 
        for(int i =1; i < nums.size(); i++){
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i-1] : 0); 
            maxv = max(dp[i], maxv);
        }
        return maxv; 
    }
};
