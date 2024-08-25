class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // create first map

        

        map <int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        // create second map

        map <int,vector<int>> m2;

        for(auto it: m){

            m2[it.second].push_back(it.first);
        }

        map <int,vector<int>>  ::iterator it;
        vector<int> result;
        
        if(--m2.end() == m2.begin()){
            return {m2.begin()->second};
        }

        for(it = --m2.end(); it!= --m2.begin() && k !=0; --it){
          if(it->second.size() <=k){
                result.insert( result.end(), it->second.begin(), it->second.end() );
                k = k - it->second.size();

            }
            else {
                result.insert(result.end(), it->second.begin(), it->second.begin() + k);
                k = 0;
            }
         
        }

        return result;
    }
};
