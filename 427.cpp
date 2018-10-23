class Solution {
private:
    Node* dfs(vector<vector<int>>& grid, int x, int y, int length) {
        if (length == 1) {
            return new Node(grid[x][y] == 1, true, nullptr, nullptr, nullptr, nullptr);
        }
        
        int newLength = length / 2;
        Node* topLeft = dfs(grid, x, y, newLength);
        Node* topRight = dfs(grid, x, y + newLength, newLength);
        Node* botLeft = dfs(grid, x + newLength, y, newLength);
        Node* botRight = dfs(grid, x + newLength, y + newLength, newLength);
        
        if (topLeft -> isLeaf && topRight -> isLeaf && botRight -> isLeaf && botLeft -> isLeaf &&
            ((topLeft -> val && topRight -> val && botLeft -> val && botRight -> val) ||
            !(topLeft -> val || topRight -> val || botLeft -> val || botRight -> val))) {
            bool val = topLeft -> val;
            delete topLeft;
            topLeft = nullptr;
            delete topRight;
            topRight = nullptr;
            delete botLeft;
            botLeft = nullptr;
            delete botRight;
            botRight = nullptr;
            return new Node(val, true, nullptr, nullptr, nullptr, nullptr);
        }
        return new Node(true, false, topLeft, topRight, botLeft, botRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int N = grid.size();
        if (N == 0) {
            return nullptr;
        }
        return dfs(grid, 0, 0, N);
    }
};