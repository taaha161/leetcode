class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map <int,int> m;
        for(int i=0 ;i<nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                if(target == nums[i]*2){
                    return {m[nums[i]], i};
                }

            }else{

            m[nums[i]] = i;
            }
        }
        for(auto it : m){
            int remaining= 0;
            if(target < 0){
                remaining = target + abs(it.first);
              

            }
            else{

             remaining = target - it.first;

             
            }
               if(m.find(remaining) != m.end()){
                    if(m[remaining] < it.second){

                return { m[remaining], it.second};
                    }
                    else{
                           return {it.second, m[remaining]};

                    }
            }
           
        }
        return {0,0};



        
    }
};
