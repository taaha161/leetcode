class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> leftProducts;
        vector<int> rightProducts;

        for(int i=0; i<nums.size(); i++){
            if(i==0){
                leftProducts.push_back(1);
            }

            else{
                leftProducts.push_back( nums[i-1]*leftProducts[i-1]);
            }
            
        }
        for(int i=nums.size()-1; i>=0; i--){
            if(i==nums.size()-1){
                rightProducts.push_back(1);
            }
            else{
                rightProducts.push_back(nums[i+1]*rightProducts[nums.size()-i-2]);
            }
            
        }
        vector<int> result;

        for(int i=0;i <nums.size(); i++){
            result.push_back( leftProducts[i] * rightProducts[nums.size()-i-1]);
        }
        
        return result;

        

    }
};
