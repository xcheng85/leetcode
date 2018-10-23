class KthLargest {
    
public:
    // default is less comparator, means the largest is on top
    priority_queue<int, vector<int>, greater<int>> pq; // smallest on top, to be deleted first
    int size;
    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop(); // the k+1 th elements to be abandoned
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */