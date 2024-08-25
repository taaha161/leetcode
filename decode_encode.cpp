class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(int i =0; i<strs.size(); i++){
            result += strs[i];
            result += '\n';
        }
        cout<< result;

        return result;

    }

    vector<string> decode(string s) {
        vector<string> result;
        int lastIndex =0;
        for(int i=0; i<s.length(); i++){ 
            if(s[i] == '\n'){
                result.push_back(s.substr(lastIndex, i-lastIndex));
                lastIndex = i+1;
            }
        }
        return result;

    }
};
