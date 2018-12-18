// main list in each step in dp

// memory footprint exceed

class Solution
{
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        int ll = s.size();

        int dict = wordDict.size();

        unordered_map<int, vector<string>> cache;

        vector<bool> dp(ll + 1, false); // substring[0, i] is breakable
        dp[0] = true;                   // empty string is breakable
        cache[0] = {""};

        // pre-scan 
        for (int i = 0; i < ll + 1; i++)
        {
            for (int j = 0; j < dict; j++)
            {
                if (dp[i]) // substr [0, i] is breakable, concat all the candidates and update dp table
                {
                    string str = s.substr(i, wordDict[j].size());
                    if (str == wordDict[j])
                    {
                        dp[i + wordDict[j].size()] = true;
                    }
                }
            }
        }
        if( !dp[ll])
            return vector<string>{};
        
        for (int i = 0; i < ll + 1; i++)
        {
            for (int j = 0; j < dict; j++)
            {
                if (dp[i]) // substr [0, i] is breakable, concat all the candidates and update dp table
                {
                    string str = s.substr(i, wordDict[j].size());
                    if (str == wordDict[j])
                    {
                        
                        dp[i + wordDict[j].size()] = true;
                        for (int k = 0; k < cache[i].size(); k++)
                        {
                             if (cache[i][k] != ""){
                                cout << cache[i][k] + " " + str << endl;
                                cache[i + wordDict[j].size()].push_back(cache[i][k] + " " + str);
                             }
                            else
                            {
                                cache[i + wordDict[j].size()].push_back(str);
                            } 
                        }
                    }
                }
            }
        }
        return cache[ll];
    }
};