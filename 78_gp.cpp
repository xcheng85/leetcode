

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results; 
        vector<int> current; 
        
        backtracking(nums, 0, current, results); 
        
        return results; 
    }
    
    
    void backtracking(vector<int>& nums, int idx, vector<int>& current, vector<vector<int>>& results){
        
            results.push_back(current);
        
            for(int i = idx; i < nums.size(); i++){
                current.push_back(nums[i]);
                backtracking(nums, i + 1, current, results);
                current.pop_back(); 
            }
    }
};