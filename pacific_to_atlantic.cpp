class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>res;

        vector<vector<bool>> connected(heights.size(), vector<bool>(heights[0].size(), false));
        

        for(int i=0; i<heights.size();i++){
            for(int j=0; j<heights[0].size(); j++){
                bool pacific = false;
                bool atlantic = false;
                        vector<vector<bool>> visited(heights.size(), vector<bool>(heights[0].size(), false));
                if(bfs(connected, visited,i,j, heights, pacific, atlantic)){
                    connected[i][j] = true;
                    res.push_back({i,j});
                }

            }
        }
        return res;
        
    }

    bool bfs( vector<vector<bool>>& connected, vector<vector<bool>>& visited, int r, int c, vector<vector<int>>& heights, bool& pacific, bool& atlantic){

        if(r<0 || r>= heights.size() || c<0 || c >= heights[0].size()){
            return false;
        }

        if(connected[r][c]) return true;
    
    

       if(r== 0 || c == 0){
        pacific = true;
       }

       if(r==heights.size()-1 || c == heights[0].size()-1){
        atlantic = true;
       }

       if(pacific && atlantic){
        return true;
       }
       visited[r][c] = true;
       bool checkLeft = false;
       bool checkRight = false;
       bool checkUp = false;
       bool checkDown = false;

       if(r+1 < heights.size() && heights[r+1][c] <= heights[r][c] && !visited[r+1][c]){
        checkDown = bfs(connected, visited,r+1,c, heights, pacific, atlantic);
       }
       if(r-1 >= 0 && heights[r-1][c] <= heights[r][c] && !visited[r-1][c]){
        checkUp = bfs( connected, visited, r-1, c, heights, pacific, atlantic);
       }
       if(c+1 < heights[0].size()&& heights[r][c+1] <= heights[r][c]&& !visited[r][c+1]){
        checkRight =    bfs(connected, visited, r, c+1, heights, pacific, atlantic) ;
       }

       if(c-1 >= 0 && heights[r][c-1] <= heights[r][c]&& !visited[r][c-1]){
        checkLeft =  bfs(connected, visited, r, c-1, heights, pacific, atlantic);
       }


       return checkLeft ||
             checkUp  ||
           checkRight || checkDown
             ;



    }
};