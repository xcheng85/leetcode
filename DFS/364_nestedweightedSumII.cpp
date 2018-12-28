/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
  public:
    int depthSumInverse(vector<NestedInteger> &nestedList)
    {
        vector<int> sumPerDepth; //
        dfs(nestedList, 1, sumPerDepth);

        int ans = 0;
        int weight = 1;

        for (int i = sumPerDepth.size() - 1; i >= 0; i--)
        {
            cout << sumPerDepth[i] << endl;
            ans += weight * sumPerDepth[i];
            weight++;
        }
        return ans;
    }

    void dfs(vector<NestedInteger> &nestedList, int depth, vector<int> &levelCache)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
            {
                if (levelCache.size() < depth)
                    levelCache.resize(depth);
                levelCache[depth - 1] += nestedList[i].getInteger();
            }
            else
            {
                dfs(nestedList[i].getList(), depth + 1, levelCache);
            }
        }
    }
};