// difference with 421
// subarray does not mean consecutive

/* Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28. */
#include <vector>
using namespace std;

struct TrieNode
{
    struct TrieNode *children[2]; // 0 or 1
    int val;

    TrieNode() : val(0)
    {
        for (int i = 0; i < 2; i++)
        {
            children[i] = nullptr;
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

    void insert(int num)
    {
        // 32 bits
        TrieNode *currentNode = m_root;

        for (int i = 31; i >= 0; i--)
        {
            // Find current bit in given prefix
            bool current_bit = (num & (1 << i));

            // Add a new Node into trie
            if (currentNode->children[current_bit] == nullptr)
            {
                TrieNode *tmp = new TrieNode();
                currentNode->children[current_bit] = tmp;
                currentNode = tmp;
            }
            else
            {
                currentNode = currentNode->children[current_bit];
            }
        }

        // store value at leafNode
        currentNode->val = num;
    }

    // Returns minimum XOR value of an integer inserted
    // in Trie and given key.
    int maxXORUtil(int num) // try to find the opposite bit at every position
    {
        TrieNode *currentNode = m_root;

        for (int i = 31; i >= 0; i--)
        {
            // Find current bit in given prefix
            bool current_bit = (num & (1 << i));

            // Traversal Trie, look for prefix that has
            // opposite bit
            if (currentNode->children[1 - current_bit] != nullptr)
                currentNode = currentNode->children[1 - current_bit];

            // if there is no same bit.then looking for
            // same bit
            else if (currentNode->children[current_bit] != nullptr)
                currentNode = currentNode->children[current_bit];
        }

        // return xor value of minimum bit difference value
        // so we get max xor value
        return num ^ currentNode->val;
    }

  private:
    TrieNode *m_root;
};

class Solution
{
  public:
    int findMaximumXORSubArray(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;

        Trie myTrie;
        myTrie.insert(nums[0]);

        int result = INT_MIN;

        for (int i = 1; i < nums.size(); i++)
        {
            // Find minimum XOR value of current element with
            // previous elements inserted in Trie

            // no need to insert all the nums before do maxXOR, because the last one will compare with all previou num anyway.
            int tmpResult = myTrie.maxXORUtil(nums[i]);
            myTrie.insert(tmpResult);
            result = max(result, tmpResult);
        }

        return result;
    }
};