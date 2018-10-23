class NumArray {
private: 
    vector<int> m_prefixSum; 
    
public:
    NumArray(vector<int> nums) {
        m_prefixSum.resize(nums.size() + 1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            m_prefixSum[i+1] = m_prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
         return m_prefixSum[j + 1] - m_prefixSum[i]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */

