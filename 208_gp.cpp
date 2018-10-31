class TrieNode
{
public:
    TrieNode *next[26];
    bool is_word;
    
    // Initialize your data structure here.
    TrieNode(bool b = false)
    {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

class Trie {
private: 
    TrieNode* m_root; 

public:
    /** Initialize your data structure here. */
    Trie() {
        m_root = new TrieNode(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* current = this->m_root; 
        int startIdx = 0;
        for(int i = 0; i < word.size(); i++){
            char c = word[i]; 
            if(current->next[c - 'a'] != NULL){
                current = current->next[c - 'a']; 
            }else{
                current -> next[c- 'a'] = new TrieNode();
                current = current ->next[c - 'a'];
            }
        }
        
        current->is_word = true; 
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* current = this->m_root; 
        for(int i = 0; i < word.size(); i++){
            char c = word[i]; 
            if(current->next[c - 'a'] != NULL){
                current = current->next[c - 'a']; 
            }else{
                return false;
            }
        }
                    return current -> is_word; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* current = this->m_root; 
        for(int i = 0; i < prefix.size(); i++){
            char c = prefix[i];
            if(current->next[c - 'a'] != NULL){
                current = current->next[c - 'a']; 
            }else{
                return false;
            }
        }
        return true; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */