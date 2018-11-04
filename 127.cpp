class Solution
{
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> bfs;
        unordered_set<string> cache(wordList.begin(), wordList.end());

        int dist = 1;
        bfs.push(beginWord);

        while (!bfs.empty())
        {
            int num = bfs.size();
            for (int i = 0; i < num; i++)
            {
                string current = bfs.front();
                bfs.pop();
                if (current == endWord)
                    return dist;

                cache.erase(current);
                for (int c = 0; c < current.size(); c++)
                {
                    for (int a = 0; a < 26; a++)
                    {
                        string tmp = current;
                        tmp[c] = 'a' + a;
                        if (cache.find(tmp) != cache.end())
                        {
                            bfs.push(tmp);
                        }
                    }
                }
            }
            dist++;
        }
        return 0;
    }
};
