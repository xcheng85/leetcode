/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result; 
        if(intervals.size() == 0)
            return result; 
        
        sort(intervals.begin(), intervals.end(), [](const Interval &a, const Interval &b){return a.start < b.start;});
        result.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            Interval last = result.back(); 
            
            if (intervals[i].start > last.end) {
                result.push_back(intervals[i]);
            }else{
                Interval tmp;
                tmp.start = last.start; 
                tmp.end = max(last.end, intervals[i].end); 
                result.pop_back(); 
                result.push_back(tmp);
            }
        } 
        return result; 
    }
};