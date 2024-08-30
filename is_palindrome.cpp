class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> temp;
   
        for(int i=0; i<s.length(); i++){
            if((s[i] < 'A' || s[i] > 'z') && (s[i] < '0' || s[i]>'9')){
                continue;
            }
            temp.push_back(tolower(s[i]));  
            
            
        }
        
        int j=temp.size()-1;

        for(int i=0; i<temp.size() / 2; i++){
                cout<<temp[i];
               
        
            if(temp[j] == temp[i]){
                j--;
            }
            else if(i == j){
                return true;
            }
            else{
               
                return false;
            }

        }
        
    }
};
