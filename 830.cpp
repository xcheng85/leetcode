class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int i = 0; 
        vector<vector<int>> result; 
        
        while(i < S.length()){
            int j = i + 1; 
            while(j < S.length()){
                if(S[j] == S[i]){
                    j++;
                }else{
                    if(j - i >=3){
                        vector<int> oneResult; 
                        oneResult.push_back(i); 
                        oneResult.push_back(j-1);
                        result.push_back(oneResult); 
                    }
                    i = j; 
                    break;              
                }
            }
            if(j == S.length()){
                 if(j - i >=3){
                        vector<int> oneResult; 
                        oneResult.push_back(i); 
                        oneResult.push_back(j-1);
                        result.push_back(oneResult); 
                    }
                i = j; 
                break; 
            }
            
        }
        
        return result; 
    }
};