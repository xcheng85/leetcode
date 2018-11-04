class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(); 
        int cols = matrix.size() > 0 ? matrix[0].size() : 0; 
        bool isCol = false;
        for(int i = 0; i < rows; i++){
            
            if (matrix[i][0] == 0) {
                isCol = true;
            }
            
            
            
            
            for(int j = 1; j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0] == 0){
            for(int c = 1; c < cols; c++){
                matrix[0][c] = 0;
            }
        }
        
        if(isCol){
            for(int r = 0; r < rows; r++){
                matrix[r][0] = 0;
            }
        }
        
        return; 
    }
};