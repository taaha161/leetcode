class Solution {
public:
    int trap(vector<int>& height) {
        int i=0;
        int j = height.size()-1;
        int water = 0;
        int rightMax =height[j];
        int leftMax =height[i] ;
        while(i<j){
          if(height[i] < height[j]){
            i++;
            leftMax = max(leftMax, height[i]);
            water += leftMax - height[i];

          }
          else{
            j--;
            rightMax = max(rightMax, height[j]);
            water += rightMax - height[j];

          }
            
        }
        return water;
        
    }
};
