class Solution
{
  public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int index[26];
        for (int i = 0; i < order.size(); ++i)
            index[order[i] - 'a'] = i;

        for (int i = 0; i < words.size() - 1; ++i)
        {
            string word1 = words[i];
            string word2 = words[i + 1];

            // Find the first difference word1[k] != word2[k].
            bool cmp = false;
            bool isOrdered = false;
            for (int k = 0; k < min(word1.size(), word2.size()); ++k)
            {
                if (word1[k] != word2[k])
                {
                    cmp = true;
                    // If they compare badly, it's not sorted.
                    if (index[word1[k] - 'a'] > index[word2[k] - 'a'])
                    {
                        cout << word1[k] << " " << word2[k] << endl;
                        return false;
                    }
                    else if (index[word1[k] - 'a'] < index[word2[k] - 'a'])
                    {
                        isOrdered = true;
                        break;
                    }
                }
            }
            if (isOrdered)
                continue;

            // If we didn't find a first difference, the
            // words are like ("app", "apple").
            if (!cmp && word1.size() > word2.size())
                return false;
        }

        return true;
    }
};