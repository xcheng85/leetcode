class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0; 
        queue<pair<int, int>> bfs; 
        int nx[4] = {1, 0, -1, 0}; 
        int ny[4] = {0, 1, 0, -1};
        
        
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){ 
                if(grid[r][c] == '1'){
                    bfs.push(make_pair(r, c));
                    grid[r][c] = '2'; 
                    while(bfs.empty() == false){
                    pair<int, int> current = bfs.front(); 
                    bfs.pop(); 
                    cout << current.first << ' ' << current.second << endl; 

                    for(int i = 0; i < 4; i++){
                        int x = current.first + nx[i]; 
                        int y = current.second + ny[i]; 
                        
                        if(x>=0 && x<grid.size() && y>=0 && y < grid[0].size()){
                            if(grid[x][y] == '1'){
                                bfs.push(make_pair(x, y));
                                grid[x][y] = '2';
                            }
                        }
                    }     
                }
                
                result++;
                }
                
                 
            }
        }
        
        return result; 
        
    }
};