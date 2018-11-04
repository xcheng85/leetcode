class Solution
{
  public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        queue<vector<string>> bfs;
        unordered_set<string> cache(wordList.begin(), wordList.end());

        bfs.push(vector<string>{beginWord});

        while (!bfs.empty())
        {
            int num = bfs.size();
            for (int i = 0; i < num; i++)
            {
                vector<string> current = bfs.front();
                bfs.pop();
                if (current.back() == endWord)
                    ans.push_back(current);

                cache.erase(current.back());
                for (int c = 0; c < current.back().size(); c++)
                {
                    for (int a = 0; a < 26; a++)
                    {
                        string tmp = current.back();
                        tmp[c] = 'a' + a;
                        if (cache.find(tmp) != cache.end())
                        {
                            current.push_back(tmp);
                            bfs.push(current);
                            current.pop_back();
                        }
                    }
                }
            }
            if (ans.size() > 0)
                return ans;
        }
        return ans;
    }
};