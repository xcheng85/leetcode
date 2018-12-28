class Solution
{
  private:
    vector<vector<int>> rects;
    vector<int> psum; // use area . area represent probility

  public:
    Solution(vector<vector<int>> rects)
    {
        this->rects = rects;
        for (auto &x : rects)
        {
            // area
            tot += (x[2] - x[0] + 1) * (x[3] - x[1] + 1);
            psum.push_back(tot);
        }
    }

    vector<int> pick()
    {
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(rects);
 * vector<int> param_1 = obj.pick();
 */