//https://briangordon.github.io/2014/08/the-skyline-problem.html
class Solution
{
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<pair<int, int>> res;
        int cur = 0, cur_X, cur_H, len = buildings.size();
        priority_queue<pair<int, int>> liveBlg;
        while (cur < len || !liveBlg.empty())
        {
            //entering case 
            if (liveBlg.empty() || cur < len && buildings[cur][0] <= liveBlg.top().second)
            {
                cur_X = buildings[cur][0];
                while (cur < len && buildings[cur][0] == cur_X)
                {
                    // same x sort by height
                    // stl pq is max queue by first, which is the height of building , sort by height, 
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            else
            {  
                // exit case, choose the smallest one
                cur_X = liveBlg.top().second;
                while (liveBlg.size() && liveBlg.top().second <= cur_X)
                    liveBlg.pop();
            }
            // highest building
            cur_H = liveBlg.empty() ? 0 : liveBlg.top().first;
            // a new height 
            if (res.empty() || (res.back().second != cur_H))
                res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};