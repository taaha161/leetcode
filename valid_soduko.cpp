class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map <char, int> rowCheck;
        map <char, int> columnCheck;
        map <char, int> boxCheck;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){

                rowCheck[board[i][j]]++;
                if(rowCheck[board[i][j]] > 1){
                    cout<<"Row false";
                    return false;
                }
                }
            }
            rowCheck.clear();
        }
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[j][i] != '.'){

                
                columnCheck[board[j][i]]++;
                if(columnCheck[board[j][i]] > 1){
                    cout<< "Column false";
                    return false;
                }}
            }
            columnCheck.clear();
        }
 
        
       for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                map<char, int> boxCheck;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        int currentRow = boxRow * 3 + i;
                        int currentCol = boxCol * 3 + j;
                        if (board[currentRow][currentCol] != '.') {
                            boxCheck[board[currentRow][currentCol]]++;
                            if (boxCheck[board[currentRow][currentCol]] > 1) {
                                cout << "Subbox false" << endl;
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;


        
    }
};
