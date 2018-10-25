class Solution
{
  public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> mySet(wordDict.begin(), wordDict.end()); 
        int n = s.size(); 
        vector<bool> breakable(n+1, false); 
        breakable[0] = true; 

        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(breakable[j] && mySet.find(s.substr(j, i - j))!=mySet.end()){
                    breakable[i] = true;
                    break;
                }
            }
        }

         return breakable[s.size()];
    }
};