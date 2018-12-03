/* Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False */

// ist of non-repetitive words to build a dictionary.
// only lower case

class MagicDictionary
{
  public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for (auto &word : dict)
        {
            m_cache.insert(word);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            const char tmp = word[i];
            for (int j = 0; j < 26; j++)
            {
                if (tmp == 'a' + j)
                {
                    continue;
                }
                else
                {
                    word[i] = 'a' + j;
                    if (m_cache.find(word) != m_cache.end())
                    {
                        return true;
                    }
                    word[i] = tmp;
                }
            }
        }

        return false;
    }

  private:
    unordered_set<string> m_cache;
};
