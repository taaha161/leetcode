class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rowStart = 0;
    int rowEnd= matrix.size() -1;
    int rowMid;
    while(rowStart <= rowEnd){
         rowMid = rowStart + (rowEnd - rowStart) / 2;
         if(matrix[rowMid][matrix[rowMid].size()-1] < target){
            rowStart = rowMid + 1;
         }
         else if(matrix[rowMid][0] > target){
            rowEnd = rowMid - 1;
         }
         else{
            break;
         }
         
        
    }
    if(rowStart> rowEnd){
        return false;
    }
     int colStart = 0;
         int colEnd = matrix[rowMid].size() - 1;
        while(colStart <= colEnd ){
            int colMid = colStart + (colEnd - colStart) / 2;
            if(matrix[rowMid][colMid] == target){
                return true;
            }
            if(matrix[rowMid][colMid] > target){
                colEnd = colMid -1;
            }
            else{
                colStart = colMid + 1;
            }
        }
    return false;
        
    }


};
