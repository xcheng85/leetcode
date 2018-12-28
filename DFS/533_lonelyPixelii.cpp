class Solution
{
  public:
    
    // row has N black pixels
    int findBlackPixel(vector<vector<char>> &picture, int N)
    {
        int m = picture.size();
        if (m == 0)
            return 0;

        int n = picture[0].size();
        if (n == 0)
            return 0;

        unordered_map<string, int> cache;
        vector<int> colCount(n, 0);

        for (int i = 0; i < m; i++)
        {
            string key = scanRow(picture, i, N, colCount);
            if (key.size() != 0)
            {
                cache[key]++;
            }
        }

        int result = 0;
        // Get an iterator pointing to begining of map
        std::unordered_map<std::string, int>::iterator it = cache.begin();

        // Iterate over the map using iterator 
        while (it != cache.end())
        {
            if (it->second == N)
            {
                for (int j = 0; j < n; j++)
                {
                    if (it->first[j] == 'B' && colCount[j] == N)
                    {
                        result += N;
                    }
                }
            }
            it++;
        }

        return result;
    }

  private:

    string scanRow(vector<vector<char>> &picture, int row, int target, vector<int> &colCount)
    {
        int n = picture[0].size();
        int rowCount = 0;

        string s;

        for (int j = 0; j < n; j++)
        {
            if (picture[row][j] == 'B')
            {
                rowCount++;
                colCount[j]++;
            }
            s += picture[row][j];
        }

        // exacely N black pixels
        if (rowCount == target)
            return s;
        return "";
    }

};