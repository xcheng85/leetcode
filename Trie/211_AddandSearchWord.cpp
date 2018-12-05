//regular expression string containing only letters a-z or .. A . means it can represent any one letter.
/* addWord("bad") */
/* addWord("dad") */
/* addWord("mad") */
/* search("pad") -> false */
/* search("bad") -> true */
/* search(".ad") -> true */
/* search("b..") -> true */
#include <stdio.h>

struct TrieNode
{
    struct TrieNode *children[26]; // lower case alpha
    bool isWord;

    TrieNode() : isWord(false)
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
            currentNode = currentNode->children[c - 'a'];
        }

        // store value at leafNode
        currentNode->isWord = true;
    }

    bool search(string wordWithRex)
    {
        bool ans = false;
        backtracking(m_root, wordWithRex, 0, ans);
        return ans;
    }

    void backtracking(TrieNode *currentNode, string wordWithRex, int currentIndx, bool &exist)
    {
        if (currentIndx == wordWithRex.size())
        {
            exist = currentNode->isWord;
            return;
        }
        else
        {
            if (wordWithRex[currentIndx] == '.')
            {
                for (int i = 0; i < 26; i++)
                {
                    if (currentNode->children[i] != nullptr)
                    {
                        backtracking(currentNode->children[i], wordWithRex, currentIndx + 1, exist);
                        if (exist)
                        {
                            return;
                        }
                    }
                }
            }
            else
            {
                if (currentNode->children[wordWithRex[currentIndx] - 'a'] != nullptr)
                {
                    backtracking(currentNode->children[wordWithRex[currentIndx] - 'a'], wordWithRex, currentIndx + 1, exist);
                }
                else
                {
                    return;
                }
            }
        }
    }

  private:
    TrieNode *m_root;
};

class WordDictionary
{
  public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        m_trie = new Trie();
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        m_trie->insert(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return m_trie->search(word);
    }

  private:
    Trie *m_trie;
};