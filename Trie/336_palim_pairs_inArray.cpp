// idea is insert the reverse of original word into trie

/* nput: ["abcd","dcba","lls","s","sssll"] */

dcba abcd sll s llsss
/* Output: [[0,1],[1,0],[3,2],[2,4]]  */
/* Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"] */

#include <string>
#include <vector>

    struct TrieNode
{
    struct TrieNode *children[26]; // lower case alpha
    bool isWord;
    int idx;
    vector<int> leftOverPartPalindrome;

    TrieNode() : isWord(false), idx(-1)
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

    void insert(string word, int idx)
    {
        // reverse
        TrieNode *currentNode = m_root;

        for (int i = word.size() - 1; i >= 0; i--)
        {
            if (currentNode->children[word[i] - 'a'] == NULL)
            {
                currentNode->children[word[i] - 'a'] = new TrieNode();
            }

            // If current word is palindrome till this
            // level, store index of current word.
            // key
            // sss ll [0, 2]  ll sss [string.size()- i -1, string.size()- 1]
            // isPalindrome(word, 0, i) == isPalindrome(reverseword, 0, i) // check the leftover part is palindrome
            if (isPalindrome(word, 0, i))
                (currentNode->leftOverPartPalindrome).push_back(idx);

            currentNode = currentNode->children[word[i] - 'a'];
        }

        // store value at leafNode

        currentNode->isWord = true;
        currentNode->idx = idx;
        currentNode->leftOverPartPalindrome.push_back(idx); // empty is also the case
    }

    void findReverseIdx(string &word, int idx, vector<vector<int>> &result)
    {
        TrieNode *current = m_root;
        for (int i = 0; i < word.size(); i++)
        {

            // If it is present also check upto which index
            // it is palindrome
            if (current->isWord && current->idx >= 0 && current->idx != idx && isPalindrome(word, i, word.size() - 1))
                result.push_back({idx, current->idx});

            // If not present then return
            if (!current->children[word[i] - 'a'])
                return;

            current = current->children[word[i] - 'a'];
        }
        for (auto i : current->leftOverPartPalindrome)
        {
            if (i == idx)
                continue;
            result.push_back({idx, i});
        }
    }

    bool isPalindrome(string &word, int i, int j)
    {
        while (i <= j)
        {
            if (word[i] == word[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

  private:
    TrieNode *m_root;
};

class Solution
{
  public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        vector<vector<int>> ans;
        m_trie = new Trie();

        int idx = 0;
        for (auto &word : words)
        {
            m_trie->insert(word, idx++);
        }

        for (int i = 0; i < words.size(); i++)
        {
            m_trie->findReverseIdx(words[i], i, ans);
        }

        return ans;
    }

  private:
    Trie *m_trie;
};