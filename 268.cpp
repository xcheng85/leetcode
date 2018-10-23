class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums.size() || nums[i] == i){
                continue; 
            }else{
                while(nums[i] != i && nums[i] != nums.size()){
                    int tmp = nums[nums[i]]; 
                    nums[nums[i]] = nums[i]; 
                    nums[i] = tmp;
                }
            }
            
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums.size()){
                return i; 
            }
        }
        return nums.size(); 
    }
};