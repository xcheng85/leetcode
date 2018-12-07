/* Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"] */

/* Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat". */

//All the input string will only include lower case letters.

// trie + backtracking
#include <vector>
using namespace std;
struct TrieNode
{
    TrieNode *children[26];
    bool isWord;
    int count; // 

    TrieNode() : isWord(false), count(0)
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

    virtual ~Trie()
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
        TrieNode *current = m_root;
        current->count++;

        for (auto &c : word)
        {
            if (current->children[c - 'a'] == NULL)
            {
                current->children[c - 'a'] = new TrieNode();
            }
            current = current->children[c - 'a'];
            current->count++; 
        }

        current->isWord = true;
    }
    
    bool isWord(string word, int idx){
        TrieNode* current = m_root; 
        for(int i = idx; i < word.size(); i++){
            current = current->children[word[i] - 'a']; 
            if(current == NULL){
                return false;
            }
        }
        return current != m_root && current->isWord;
    }

    bool isConcatWord(string word, int idx){
        TrieNode* current = m_root; 
        int count = 0; 
        for(int i = idx; i < word.size(); i++){
            current = current->children[word[i] - 'a']; 
            if(current == NULL){
                return false;
            }else{
                if(current->isWord){
                    if( (isConcatWord(word, i+1) || isWord(word, i+1)) == true)
                        return true;
                }
            }
        }
        return false;
    }


  private:
    TrieNode *m_root;
};

class Solution
{
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans; 

        m_trie = new Trie();

        for (auto &word : words)
        {
            m_trie->insert(word);
        }

        for(auto &word : words){
            if(m_trie->isConcatWord(word, 0)){
                ans.push_back(word); 
            }
        }

        return ans; 
    }

  private:
    Trie *m_trie;
};