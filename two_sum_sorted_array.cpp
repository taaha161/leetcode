class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j = numbers.size()-1;

     
        while(numbers[i] + numbers[j] != target){
            int sum = numbers[i] + numbers[j];
            if(sum > target){
                j--;
            }else{
                i++;
            }

        }
        return {i+1,j+1};
       
        
    }
};
