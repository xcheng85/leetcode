class Solution
{
  public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        queue<string> bfs;
        unordered_set<string> cache(wordList.begin(), wordList.end());

        helper(beginWord, endWord, cache, bfs);
        int dist = 2;
        while (bfs.empty() == false)
        {
            int num = bfs.size();
            for (int i = 0; i < num; i++)
            {
                string current = bfs.front();
                bfs.pop();
                if (current == endWord)
                    return dist;
                helper(current, endWord, cache, bfs);
            }
            dist++;
        }
        return 0;
    }

    void helper(string currentWord, string endWord, unordered_set<string> &wordListCache, queue<string> &bfs)
    {
        wordListCache.erase(currentWord);
        for (int i = 0; i < currentWord.size(); i++)
        {
            for (int j = 0; j < 26; j++)
            {
                string tmp = currentWord;
                tmp[i] = 'a' + j;
                if (wordListCache.find(tmp) != wordListCache.end())
                {
                    bfs.push(tmp);
                }
            }
        }
    }
};