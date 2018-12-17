#include <vector>

//The number of rows and columns of grid will each be in the range [1, 200].
/* 
observation:
For each pair of 1s in the new row (say at new_row[i] and new_row[j]), we could create more rectangles where that pair forms the base. 
The number of new rectangles is the number of times some previous row had row[i] = row[j] = 1. */
class Solution
{
  public:
    int countCornerRectangles(vector<vector<int>> &grid)
    {
        unordered_map<int, int> cache; // each 
        int ans = 0; 

        for(auto& row : grid){
            for(int c1 = 0; c1 < row.size(); c1++){
                if(row[c1] == 1){
                    for(int c2 = c1 + 1; c2 < row.size(); c2++){
                        if(row[c2] == 1){
                            // find the pair
                            int cache_index = c1 * 200 + c2; 
                            int cache_num = cache[cache_index]; 
                            ans += cache_num; // initially 0
                            cache[cache_index] = cache_num + 1; 
                        }
                    }
                }
            }
        }

        return ans;
    }
};

/* 
class Solution {
    public int countCornerRectangles(int[][] grid) {
        Map<Integer, Integer> count = new HashMap();
        int ans = 0;
        for (int[] row: grid) {
            for (int c1 = 0; c1 < row.length; ++c1) if (row[c1] == 1) {
                for (int c2 = c1+1; c2 < row.length; ++c2) if (row[c2] == 1) {
                    int pos = c1 * 200 + c2;
                    int c = count.getOrDefault(pos, 0);
                    ans += c;
                    count.put(pos, c+1);
                }
            }
        }
        return ans;
    }
} */