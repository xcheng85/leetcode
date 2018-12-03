
struct TrieNode
{
    struct TrieNode *children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false)
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

    void insert(string word)
    {
        TrieNode *currentNode = m_root;
        for (auto &c : word)
        {
            if (currentNode->children[c - 'a'] == NULL)
            {
                TrieNode *tmp = new TrieNode();
                currentNode->children[c - 'a'] = tmp;
                currentNode = tmp;
            }
            else
            {
                currentNode = currentNode->children[c - 'a'];
            }
        }
        currentNode->isEndOfWord = true;
    }

    bool isInTrie(string word)
    {
        TrieNode *current = m_root;
        for (auto c : word)
        {
            if (current->children[c - 'a'] == NULL)
            {
                return false;
            }
            current = current->children[c - 'a'];
        }
        return current->isEndOfWord;
    }

    // backtracking, change one character every time
    int search(string word) // starts with ap
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

                    if (isInTrie(word))
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
    TrieNode *m_root;
};

class MagicDictionary
{
  public:
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        m_trie = new Trie();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict)
    {
        for (auto &word : dict)
        {
            m_trie->insert(word);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word)
    {
        return m_trie->search(word);
    }

  private:
    Trie *m_trie;
};