class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> lastOccurancePos(26, 0);
        for(int i = 0; i  < S.size(); i++){
            lastOccurancePos[S[i] - 'a'] = i;
        }
        int j = 0; // in a segment, the possible max position calculated in previous step, key!!!
        int anchor = 0; 
        
        vector<int> ans; 
        
        for(int i = 0; i < S.size(); i++){
            
            j = max(j, lastOccurancePos[S[i] - 'a']); 
            
            if(i == j){
                //reach the end of a possible end of segment
                ans.push_back(i - anchor + 1);        
                
                anchor = i + 1;
            }
                  
        }
        return ans; 
    }
};
