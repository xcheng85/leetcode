// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1; 
        int right = n; 
        
        while(true){
            //int mid = (left + right) / 2; 
            int mid = (right - left) / 2 + left;
            int res = guess(mid); 
            if(guess(mid) == 0)
                return mid; 
            
            if(guess(mid) < 0){
                right = mid - 1; 
            }
            if(guess(mid) > 0){
                left = mid + 1; 
            }
        }
    }
};