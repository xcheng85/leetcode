class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> myHash; 
        
        for(int i=0; i < nums.size(); i++){
            if(myHash.find(nums[i]) == myHash.end()){
                myHash[nums[i]] = i; 
            }else{
                int delta = i -  myHash[nums[i]];
                if(delta <= k){
                    return true; 
                }else{
                   myHash[nums[i]] = i; 
                }
            }
        }
        return false;
    }
};