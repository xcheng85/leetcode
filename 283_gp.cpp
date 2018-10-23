class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int currentPos = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[currentPos++] = nums[i];
            }
        }
        
        while(currentPos < nums.size()){
            nums[currentPos++] = 0;
        }
        
    }
};
