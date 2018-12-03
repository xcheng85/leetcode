/* Input: insert("apple", 3), Output: Null
Input: sum("ap"), Output: 3
Input: insert("app", 2), Output: Null
Input: sum("ap"), Output: 5 */

struct TrieNode
{
    // similar like a hash map
    struct TrieNode *children[26];

    // isEndOfWord is true if the node
    // represents end of a word
    bool isEndOfWord;
    int val;

    TrieNode() : isEndOfWord(false), val(0)
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

    void insert(string word, int value)
    {
        int diff = value;
        if (m_cache.find(word) != m_cache.end())
        {
            diff = value - m_cache[word];
        }
        m_cache[word] = value;

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
            currentNode->val += diff;
        }
        currentNode->isEndOfWord = true;
    }

    // loop all node in the tree
    int dfs(string prefix) // starts with ap
    {
        TrieNode *currentNode = m_root;
        for (auto &c : prefix)
        {
            if (currentNode->children[c - 'a'] == NULL)
            {
                currentNode = NULL;
                break;
            }
            else
            {
                currentNode = currentNode->children[c - 'a'];
            }
        }

        if (currentNode == NULL)
        {
            return 0;
        }
        else
        {
            return currentNode->val;
        }
    }

  private:
    TrieNode *m_root;
    unordered_map<string, int> m_cache; // for overiding same key
};

class MapSum
{
  public:
    /** Initialize your data structure here. */
    MapSum()
    {
        m_trie = new Trie();
    }

    void insert(string key, int val)
    {
        m_trie->insert(key, val);
    }

    int sum(string prefix)
    {
        return m_trie->dfs(prefix);
    }

  private:
    Trie *m_trie;
};