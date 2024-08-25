class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <map<char,int>, vector<string>> m;
        // create maps

        for(int i=0; i<strs.size(); i++){
            map <char, int> tempMap;
            for(int j=0; j<strs[i].length(); j++){
                tempMap[strs[i][j]]++;
            }
            m[tempMap].push_back(strs[i]);    
        }

        vector<vector<string>> result;

        for(auto it: m){
            result.push_back(it.second);
        }
        return result;

        
    }
};
