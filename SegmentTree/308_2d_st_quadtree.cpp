class NumMatrix
{
    struct TreeNode
    {
        int val = 0; // sum 
        TreeNode *neighbor[4] = {NULL, NULL, NULL, NULL};
        pair<int, int> leftTop = make_pair(0, 0);
        pair<int, int> rightBottom = make_pair(0, 0);
        TreeNode(int v) : val(v) {}
    };

  public:
    NumMatrix(vector<vector<int>> matrix)
    {
        nums = matrix;
        if (matrix.empty())
            return;
        int row = matrix.size();
        if (row == 0)
            return;
        int col = matrix[0].size();
        // top -> down construct quadtree, 
        root = createTree(matrix, make_pair(0, 0), make_pair(row - 1, col - 1));
    }

    void update(int row, int col, int val)
    {
        int diff = val - nums[row][col];
        if (diff == 0)
            return;
        nums[row][col] = val;
        updateTree(row, col, diff, root);
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = 0;
        if (root != NULL)
            sumRegion(row1, col1, row2, col2, root, res);
        return res;
    }

  private:
    TreeNode *root = NULL;

    // local copy update
    vector<vector<int>> nums;

    TreeNode *createTree(vector<vector<int>> &matrix, pair<int, int> start, pair<int, int> end)
    {
        // recursive exit condition
        if (start.first > end.first || start.second > end.second)
            return NULL;

        TreeNode *cur = new TreeNode(0);
        cur->leftTop = start;
        cur->rightBottom = end;
        // leaf node
        if (start == end)
        {
            cur->val = matrix[start.first][start.second];
            return cur;
        }

        int midx = (start.first + end.first) / 2;
        int midy = (start.second + end.second) / 2;
        cur->neighbor[0] = createTree(matrix, start, make_pair(midx, midy));
        cur->neighbor[1] = createTree(matrix, make_pair(start.first, midy + 1), make_pair(midx, end.second));
        cur->neighbor[2] = createTree(matrix, make_pair(midx + 1, start.second), make_pair(end.first, midy));
        cur->neighbor[3] = createTree(matrix, make_pair(midx + 1, midy + 1), end);
        for (int i = 0; i < 4; i++)
        {
            if (cur->neighbor[i])
                cur->val += cur->neighbor[i]->val;
        }
        return cur;
    }

    void sumRegion(int row1, int col1, int row2, int col2, TreeNode *ptr, int &res)
    {
        pair<int, int> start = ptr->leftTop;
        pair<int, int> end = ptr->rightBottom;

        // determine whether there is overlapping
        int top = max(start.first, row1);
        int bottom = min(end.first, row2);
        
        if (bottom < top)
            return;
            
        int left = max(start.second, col1);
        int right = min(end.second, col2);
        if (left > right)
            return;

        // complete larger than current node
        if (row1 <= start.first && col1 <= start.second && row2 >= end.first && col2 >= end.second)
        {
            res += ptr->val;
            return;
        }

        for (int i = 0; i < 4; i++)
            if (ptr->neighbor[i])
                sumRegion(row1, col1, row2, col2, ptr->neighbor[i], res);
    }

    void updateTree(int row, int col, int diff, TreeNode *ptr)
    {
        if (row >= (ptr->leftTop).first && row <= (ptr->rightBottom).first &&
            col >= (ptr->leftTop).second && col <= (ptr->rightBottom).second)
        {
            ptr->val += diff;
            for (int i = 0; i < 4; i++)
                if (ptr->neighbor[i])
                    updateTree(row, col, diff, ptr->neighbor[i]);
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */