class Solution {
public:
    int climbStairs(int n) {
        if(n < 0)
            return 0; 
        int pre = 1; // n = 1
        int cur = 2; // n = 2
        
        if(n == 1){
            return pre;
        }
        if(n== 2)
            return cur;
        
        for(int i = 3; i <= n; i++){
            int tmp = cur; 
            cur = cur + pre; 
            pre = tmp;
        }
        
        return cur; 
    }
};