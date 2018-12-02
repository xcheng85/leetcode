// only consider lower-case
struct TrieNode
{
    // similar like a hash map
    struct TrieNode *children[26];

    // isEndOfWord is true if the node
    // represents end of a word
    bool isEndOfWord;
    int indexOfInputArray; // compare lexi order

    TrieNode() : isEndOfWord(false), indexOfInputArray(-1)
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

    void insert(string word, int index)
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
        currentNode->indexOfInputArray = index;
    }

    bool isWord(string word)
    {
        TrieNode *currentNode = m_root;

        for (auto &c : word)
        {
            int index = c - 'a';
            if (!currentNode->children[index])
                return false;

            currentNode = currentNode->children[index];
        }

        return (currentNode != NULL && currentNode->isEndOfWord);
    }

    string search()
    {
        string ans = "";
        int maxvalue = 0;
        backtracking(m_root, 0, "", maxvalue, ans);

        return ans;
    }

    // backtracking
    void backtracking(TrieNode *r, int curr, string currstr, int &max, string &ans)
    {
        TrieNode *temp = r;

        //For each node check all alphabets from a-z (Since lexico)
        for (int i = 0; i < 26; i++)
        {
            if (temp->children[i] == NULL)
                continue;

            if (temp->children[i]->isEndOfWord)
            {
                // lenght
                curr++;
                currstr += (char)(i + 'a');

                // cout<<"--------------------"<<endl;
                // cout<<" Word: "<<(char)(i+'a')<<"   "<<curr<<"  y: "<<currstr<<endl;
                ans = curr > max ? currstr : ans;
                max = curr > max ? curr : max;

                // cout<<" Word: "<<(char)(i+'a')<<"   "<<max<<"  y: "<<ans<<endl;
                // cout<<"--------------------"<<endl;
                backtracking(temp->children[i], curr, currstr, max, ans);

                curr--;
                currstr.pop_back();
            }
        } //for
    }

  private:
    TrieNode *m_root;
};

class Solution
{
  public:
    string longestWord(vector<string> &words)
    {
        Trie trie;
        int index = 0;
        for (auto word : words)
        {
            trie.insert(word, index++);
        }
        return trie.search();
    }
};