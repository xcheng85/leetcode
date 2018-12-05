struct TrieNode
{
    struct TrieNode *children[27]; // lower case alpha + " "
    vector<string> sentences;      // words start with this prefix node. avoid dfs, cache it during the insertion

    TrieNode()
    {
        for (int i = 0; i < 27; i++)
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
        for (int a = 0; a < 27; a++)
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

    void insert(string sentence)
    {
        TrieNode *currentNode = m_root;

        for (const auto &c : sentence)
        {
            if (c == ' ')
            {
                if (currentNode->children[26] == NULL)
                {
                    currentNode->children[26] = new TrieNode();
                }
                currentNode = currentNode->children[26];
            }
            else
            {
                if (currentNode->children[c - 'a'] == NULL)
                {
                    currentNode->children[c - 'a'] = new TrieNode();
                }
                currentNode = currentNode->children[c - 'a'];
            }
            currentNode->sentences.push_back(sentence);
        }
    }

    vector<string> findSentencesByPrefix(string prefix)
    {
        TrieNode *currentNode = m_root;

        for (auto &c : prefix)
        {
            if (currentNode)
            {
                currentNode = (c == ' ' ? currentNode->children[26] : currentNode->children[c - 'a']);
            }
            else
                break;
        }
        if (currentNode)
        {
            //cout << "prefix:" << prefix << endl;
            //cout << "found:" << currentNode->sentences.size() << endl;
            return currentNode->sentences;
        }
        else
        {
            //cout << "not found" << endl;
            return {};
        }
    }

  private:
    TrieNode *m_root;
};

class Compare
{
  public:
    bool operator()(pair<int, string> &left, pair<int, string> &right)
    {
        // min on top
        return left.first > right.first || (left.first == right.first && left.second < right.second);
    }
};

class AutocompleteSystem
{
  public:
    AutocompleteSystem(vector<string> sentences, vector<int> times)
    {
        m_trie = new Trie();

        for (int i = 0; i < sentences.size(); i++)
        {
            m_trie->insert(sentences[i]);
            m_cache[sentences[i]] = times[i];
        }
    }

    vector<string> input(char c)
    {
        if (c == '#')
        {
            cout << m_input << endl;
            if (m_cache.find(m_input) == m_cache.end())
                m_trie->insert(m_input);

            m_cache[m_input]++;
            m_input.clear();
            return {};
        }
        else
        {
            m_input.push_back(c);
            vector<string> matched = m_trie->findSentencesByPrefix(m_input);

            for (auto s : matched)
            {
                //cout << 'ttt: ' << s <<endl;
            }
            // top3
            matched = topKFrequent(matched, 3);
            return matched;
        }
    }

  private:
    vector<string> topKFrequent(vector<string> &matchedSentences, int k)
    {
        vector<string> result;

        // min Priority Queue , small to larger
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

        for (auto &s : matchedSentences)
        {
            if (m_cache[s] > 0)
            {
                pq.push(make_pair(m_cache[s], s));
                if (pq.size() > k)
                {
                    pq.pop(); //the min
                }
            }
        }

        while (!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }

    Trie *m_trie;
    unordered_map<string, int> m_cache;
    string m_input;
};