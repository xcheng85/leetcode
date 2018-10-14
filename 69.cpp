class Solution {
public:
    int mySqrt(int x) {
        int left = 0; 
        int right = x; 
        
        if(x <= 1)
            return x;
        while(left <= right){
            cout << left << endl; 
            cout << right << endl; 
            
            int mid = (left + right) / 2; 
            cout << mid << endl;
            if(mid > x / mid){
                right = mid - 1; 
            }
            if(mid < x / mid && (mid + 1) > x/(mid + 1))
                return mid;
            if(mid == x/mid)
                return mid; 
            if(mid < x/mid && (mid + 1) <=x/(mid+1))
                left = mid + 1;
        }
    }
};