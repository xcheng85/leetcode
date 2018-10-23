class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int maxB[26]; 
        memset(maxB, 0, 26*sizeof(int));
        
        for(int i = 0; i < B.size(); i++){
            string tmp = B[i];
            int maxTmp[26]; 
            memset(maxTmp, 0, 26*sizeof(int));
            for(int j = 0; j < tmp.size(); j++){
                maxTmp[tmp[j] - 'a']++;
                maxB[tmp[j] - 'a'] = max(maxB[tmp[j] - 'a'], maxTmp[tmp[j] - 'a']);
            }
        }
        
        
        
        vector<string> result;
        for(int i = 0; i < A.size(); i++){
            string tmp = A[i]; 
            
            int maxA[26]; 
            memset(maxA, 0, 26*sizeof(int));
            
            for(int j = 0; j < tmp.size(); j++){
                maxA[tmp[j] - 'a']++;
            }
            
            bool isSuperSet = true;
            for(int j = 0; j < 26; j++){
                if(maxA[j] < maxB[j]){
                    isSuperSet = false;
                }
            }
            
            if(isSuperSet)
                result.push_back(tmp); 
        }
        
        return result;
    }
};