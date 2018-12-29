class Solution
{
  public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int res = 0;
        if (arrays.size() == 0)
            return 0;

        int min_val = arrays[0][0], max_val = arrays[0][arrays[0].size() - 1];

        for (int i = 1; i < arrays.size(); i++)
        {
            // this promised the different rows
            res = max(res, max(abs(arrays[i][arrays[i].size() - 1] - min_val), abs(max_val - arrays[i][0])));
            min_val = min(min_val, arrays[i][0]);
            max_val = max(max_val, arrays[i][arrays[i].size() - 1]);
        }
        return res;
    }
};