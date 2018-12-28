/*stream , 1, 3, 7, 2, 6, ..., 

continous interval ranges */

class SummaryRanges
{
  public:
    /** Initialize your data structure here. */
    void addNum(int val)
    {
        auto it = st.lower_bound(Interval(val, val));

        int start = val, end = val;
        
        if (it != st.begin() && (--it)->end + 1 < val)
            it++;
        
        while (it != st.end() && val + 1 >= it->start && val - 1 <= it->end)
        {
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        st.insert(it, Interval(start, end));
    }

    vector<Interval> getIntervals()
    {
        vector<Interval> result;
        for (auto val : st)
            result.push_back(val);
        return result;
    }

  private:
    struct Cmp
    {
        bool operator()(const Interval& a, const Interval& b) { return a.start < b.start; }
    };
    set<Interval, Cmp> st; // bst
};