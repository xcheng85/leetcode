class Solution
{
  public:
    string boldWords(vector<string> &words, string S)
    {
        vector<bool> marked(S.size(), 0);
        for (int i = 0; i < words.size(); i++)
        {
            markWords(S, words[i], marked);
        }
        string res;
        for (int i = 0; i < S.size(); i++)
        {
            if (marked[i] && (i == 0 || !marked[i - 1]))
            {
                res += "<b>";
            }
            res.push_back(S[i]);
            if (marked[i] && (i == S.size() - 1 || !marked[i + 1]))
            {
                res += "</b>";
            }
        }
        return res;
    }
    void markWords(string &S, string &word, vector<bool> &marked)
    {
        for (int i = 0; i <= S.length() - word.length(); i++)
        {
            string substr = S.substr(i, word.size());
            if (word == substr)
            {
                for (int j = i; j < i + word.size(); j++)
                {
                    marked[j] = true;
                }
            }
        }
    }
};