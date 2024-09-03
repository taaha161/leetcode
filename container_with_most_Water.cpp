class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0;
        int j= heights.size()-1;
        int maxA =0;

        while(i<j){
            int h = min(heights[i],heights[j]);
            int w = j-i;
            int area = h * w;
            maxA = max(maxA,area);
            if (heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxA;
        
    }
};
