class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int max = INT_MIN;
        int min = INT_MAX;
        
        for (int i=0; i<nums.size();i++){
            if(nums[i] > max){
                max = nums[i];
            }
            if(nums[i] < min){
                min = nums[i];
            }

        }
        if(min<0){
            min = abs(min);
        }
       
        int space = max + min;
        cout<<max;
        
        
       int* countArray = new int[space+1];
       for(int i=0; i<space+1; i++){
        countArray[i] = 0;
       }
        for(int i=0; i< nums.size(); i++){
            if(nums[i] < 0){
                int index = max + abs(nums[i]);
                countArray[index] += 1;
                 if(countArray[index] > 1){
                    cout<< index;
                return true;
            }

            }
            else{

            countArray[nums[i]] += 1;
            if(countArray[nums[i]] > 1){
                return true;
            }
            }
        }
        return false;


    }
};