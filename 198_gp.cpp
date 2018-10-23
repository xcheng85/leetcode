class Solution {
public:
    // dp with two state
    int rob(vector<int>& nums) {
        int prev1 = 0; 
        int prev2 = 0; 
        for(int i = 0; i < nums.size(); i++){
            int tmp = prev1; 
            prev1 = max(prev2 + nums[i], prev1); 
            prev2 = tmp; 
        }
        return prev1; 
    }
};