class Solution {
public:
    void helper(vector<int>& nums, int l, int r, int target, int& minTarget, int& maxTarget){
        bool found = false; 
        int m; 
        while(l <= r) {
            m = l + (r - l) / 2; 
            cout << m << endl;
            if(nums[m] == target){
                found = true;
                break; 
            }else if(nums[m] < target){ 
                l = m + 1;
            }else{
                // target is on the left half
                r = m - 1; 
            }    
        }
        if(found){
             // target is across 
            minTarget = min(minTarget, m); 
            maxTarget = max(maxTarget, m); 
            
            helper(nums, l, m - 1, target, minTarget, maxTarget); 
            helper(nums, m+ 1, r, target, minTarget, maxTarget); 
        }
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int minTarget = nums.size(); 
        int maxTarget = -1; 
        
        helper(nums, 0, nums.size() - 1, target, minTarget, maxTarget); 
        
        if(minTarget > maxTarget){
            return vector<int>{-1, -1}; 
        }else
            return vector<int>{minTarget, maxTarget};
    }
};