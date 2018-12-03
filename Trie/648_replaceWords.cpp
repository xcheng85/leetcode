//The input will only have lower-case letters.

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

    string getRoot(string word)
    {
        TrieNode *current = m_root;
        string prefix;
        for (auto c : word)
        {
            if (current->children[c - 'a'] == NULL)
            {
                break;
            }
            current = current->children[c - 'a'];
            prefix.push_back(c);
            if (current->isEndOfWord)
            {
                return prefix;
            }
        }
        return word;
    }

  private:
    TrieNode *m_root;
};

class Solution
{
  public:
    string replaceWords(vector<string> &dict, string sentence)
    {
        Trie m_trie;
        for (auto &word : dict)
        {
            m_trie.insert(word);
        }

        vector<string> words;
        std::istringstream iss(sentence);
        for (std::string s; iss >> s;)
            words.push_back(s);

        string result;
        for (int i = 0; i < words.size(); i++)
        {
            result += m_trie.getRoot(words[i]);
            if (i < words.size() - 1)
                result += " ";
        }
        return result;
    }
};