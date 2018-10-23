class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size()- 1; 
        
        // equal import
        while(left <= right){
            int mid = left + (right - left)/2; 
            int val_left = nums[left]; 
            int val_mid = nums[mid]; 
            int val_right = nums[right]; 
            
            cout  << val_left << " " << val_mid << " " << val_right  << endl; 
            
            if(target == val_mid)
                return mid;
            // equal important
            if(val_left <= val_mid){
                if(val_left <= target && target < val_mid){
                    return regularBinarySearch(nums, left, mid, target); 
                }else{
                    left = mid + 1; 
                }
            }else{
                if(val_mid < target && target <= val_right){
                    return regularBinarySearch(nums, mid, right, target); 
                }else{
                    right = mid - 1; 
                }
            }
            
            cout << left << " " << right << endl; 
        }
        
        return -1; 
    }
    
    
    int regularBinarySearch(vector<int>& nums, int l, int r, int target){
        cout << "regular" << endl; 
        
        cout << l << " " << r << endl;
        // equal important
        while(l <= r){
            int mid = l + (r - l) / 2; 
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] > target){
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return -1; 
        
    }
};