class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0; 
        
        unordered_map<char, int> myCache; 
        int currentLength = 0; 
        int minValidIndex = 0;  // key issue
        for(int i = 0; i < s.size(); i++){
            if(myCache.find(s[i]) == myCache.end() || myCache[s[i]] < minValidIndex){
                myCache[s[i]] = i;
                currentLength++; 
            }else{
                int prevPos = myCache[s[i]];
                minValidIndex = prevPos + 1; 
                
                myCache[s[i]] = i; 
                
                result = max(result, currentLength); 
                currentLength = i - prevPos; 
            }
        }
        return max(result, currentLength); 
    }
};