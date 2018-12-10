// num1, num2 already sorted by ascending

// min heap

/* try i+1, j,  i, j+1

repearted k times. 

Key issue: pair of i, j may be duplicated. Use unordered_set to cache all the processed  */

#include <vector>
struct Node
{
    int sum; // between two array elements
    pair<int, int> indexPair;

    Node(pair<int, int> p, int s) : sum(s)
    {
        indexPair = p;
    }
};

class cmp
{
  public:
    bool operator()(Node &p1, Node &p2)
    {
        return p1.sum > p2.sum || (p1.sum == p2.sum && p1.indexPair.first > p2.indexPair.first); // min heap
    }
};

class Solution
{
  public:
    vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> ans;
        if (nums1.size() == 0 || nums2.size() == 0)
            return ans;

        //cannot use unordered_set, no hash function for pair
        set<pair<int, int>> cache;
        priority_queue<Node, vector<Node>, cmp> pq;

        pq.push(Node(make_pair(0, 0), nums1[0] + nums2[0]));
        cache.insert(make_pair(0, 0));

        for (int i = 0; i < k && pq.size() > 0; i++)
        {
            Node tmp = pq.top();
            pq.pop();

            pair<int, int> current = tmp.indexPair;
            pair<int, int> new1 = make_pair(current.first + 1, current.second);
            pair<int, int> new2 = make_pair(current.first, current.second + 1);

            if (current.first + 1 < nums1.size() && cache.find(new1) == cache.end())
            {
                pq.push(Node(new1, nums1[current.first + 1] + nums2[current.second]));
                //  cout << new1.first << " " << new1.second << endl;
                cache.insert(new1);
            }

            if (current.second + 1 < nums2.size() && cache.find(new2) == cache.end())
            {
                pq.push(Node(new2, nums1[current.first] + nums2[current.second + 1]));
                //   cout << new2.first << " " << new2.second << endl;
                cache.insert(new2);
            }

            ans.push_back(make_pair(nums1[current.first], nums2[current.second]));
        }

        return ans;
    }
};