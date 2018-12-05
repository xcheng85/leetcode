struct TrieNode
{
    struct TrieNode *children[26]; // lower case alpha
    vector<string> words;          // words start with this prefix node. avoid dfs, cache it during the insertion

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class Trie
{
  public:
    Trie()
    {
        m_root = new TrieNode();
    }

    ~Trie()
    {
        clear(m_root);
    }

    void clear(TrieNode *currentNode)
    {
        for (int a = 0; a < 26; a++)
        {
            if (currentNode->children[a] != NULL)
            {
                TrieNode *tmp = currentNode->children[a];
                currentNode->children[a] = NULL;
                clear(tmp);
            }
        }
        delete currentNode;
    }

    void insert(string word)
    {
        TrieNode *currentNode = m_root;

        for (const auto &c : word)
        {
            if (currentNode->children[c - 'a'] == NULL)
            {
                currentNode->children[c - 'a'] = new TrieNode();
            }
            currentNode->words.push_back(word);
            currentNode = currentNode->children[c - 'a'];
        }
    }

    vector<string> findWordsByPrefix(string prefix)
    {
        TrieNode *currentNode = m_root;

        for (auto &c : prefix)
        {
            if (currentNode)
                currentNode = currentNode->children[c - 'a'];
            else
                break;
        }
        if (currentNode)
            return currentNode->words;
        else
            return {};
    }

  private:
    TrieNode *m_root;
};

class Solution
{
  public:
    vector<vector<string>> wordSquares(vector<string> &words)
    {
        vector<vector<string>> ans;
        vector<string> candidate;
        m_trie = new Trie();

        for (auto &word : words)
        {
            m_trie->insert(word);
        }

        backtracking(words[0].size(), ans, candidate);

        return ans;
    }

  private:
    void backtracking(int wordLength, vector<vector<string>> &ans, vector<string> &candidate)
    {
        // termination
        if (wordLength == candidate.size())
        {
            ans.push_back(candidate);
        }
        else
        {
            int currentIndx = candidate.size();
            string prefixPattern;
            // key is here
            for (auto &c : candidate)
            {
                prefixPattern.push_back(c[currentIndx]);
            }
            vector<string> allWordStartWithPrefix = m_trie->findWordsByPrefix(prefixPattern);

            for (auto &word : allWordStartWithPrefix)
            {
                candidate.push_back(word);
                backtracking(wordLength, ans, candidate);
                candidate.pop_back();
            }
        }
    }

  private:
    Trie *m_trie;
};