class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0; 
        int right = S.size() - 1; 
        string result = S;
        
        while(left < right){
          while( !((S[left] >= 'a' && S[left] <= 'z') || (S[left] >= 'A' && S[left] <= 'Z')) ){
              left++;
          }   
          while( !((S[right] >= 'a' && S[right] <= 'z') || (S[right] >= 'A' && S[right] <= 'Z')) ){
              right--;
          }       
          if(left < right){
              result[left] = S[right]; 
              result[right] = S[left]; 
              left++;
              right--;
          }
        }
        return result; 
    }
};