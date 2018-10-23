class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size() / (2*k);
        int left = s.size() % (2*k);
        
        for(int i = 0; i < n; i++){
            int startIndx = 2*k*i; 
            int endIndx = 2*k*i + k - 1; 
            
            for(int j = 0; j < k/2; j++){
                char tmp = s[j + startIndx]; 
                s[j + startIndx] = s[endIndx - j]; 
                s[endIndx - j] = tmp;
            }
        }
        
        if(left < k){
            int startIndx = n * 2 * k; 
            int endIndx = s.size() - 1; 
            for(int j = 0; j < (endIndx - startIndx + 1)/2; j++){
                char tmp = s[j + startIndx]; 
                s[j + startIndx] = s[endIndx - j]; 
                s[endIndx - j] = tmp;
            }
        }else{
            int startIndx = n * 2 * k; 
            int endIndx = n * 2 * k + k - 1; 
            for(int j = 0; j < k/2; j++){
                char tmp = s[j + startIndx]; 
                s[j + startIndx] = s[endIndx - j]; 
                s[endIndx - j] = tmp;
            }
        }
        
        return s; 
    }
};