//LCM(a, b) = (a*b) / GCD(a,b)

#include <vector>
using namespace std;

class Solution
{
  public:
    int maxOccurance(vector<int> &array, int l, int r)
    {
        this->m_size = array.size();

        m_segmentTree.resize(4 * this->m_size); // safe size

        // build frequency array from original array;

        unordered_map<int, int> hashmap;

        for (auto &a : array)
            hashmap[a]++;

        vector<int> frequencyArray(m_size, 0);
        for (int i = 0; i < m_size; i++)
        {
            frequencyArray[i] = hashmap[array[i]];
        }

        buildTree(frequencyArray, 0, m_size - 1, 0);

        return maxOccuranceQuery(l, r, 0, m_size - 1, 0);
    }

  private:
    void buildTree(vector<int> &frequencyArray, int start, int end, int currentIdx)
    {
        if (start == end)
        {
            // leaf node itself
            m_segmentTree[currentIdx] = frequencyArray[start];
            return;
        }
        else
        {
            int mid = start + (end - start) / 2;
            buildTree(frequencyArray, start, mid, 2 * currentIdx + 1);
            buildTree(frequencyArray, mid + 1, end, 2 * currentIdx + 2);

            m_segmentTree[currentIdx] = max(m_segmentTree[2 * currentIdx + 1], m_segmentTree[2 * currentIdx + 2]);
        }
    }

    int maxOccuranceQuery(int qs, int qe, int arrayStart, int arrayEnd, int currentIdx) // currentIdx --> node in tree
    {
        if (arrayStart > qe || arrayEnd < qs)
            return 0;

        // If segment of this node is a part of given
        // range, then return the node of the segment
        if (qs <= arrayStart && qe >= arrayEnd)
            return m_segmentTree[currentIdx];

        int mid = arrayStart + (arrayEnd - arrayStart) / 2;

        if (qe <= mid)
            return maxOccuranceQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);

        if (qs > mid)
            return maxOccuranceQuery(qs, qe, mid, arrayEnd, 2 * currentIdx + 2);

        // If a part of this segment overlaps with
        // the given range
        int left = maxOccuranceQuery(qs, qe, arrayStart, mid, 2 * currentIdx + 1);
        int right = maxOccuranceQuery(qs, qe, mid, arrayEnd, 2 * currentIdx + 2);

        return max(left, right);
    }

    vector<int> m_segmentTree; // only need to record the occurance num
    int m_size;
};