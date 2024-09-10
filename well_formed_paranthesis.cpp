class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursiveCall(n, 0,0, "", res);

        return res;
        
    }

private:

vector<string> recursiveCall(int n, int open, int close, string curr, vector<string>& res){
    if(open == close && open == n){
        res.push_back(curr);
        return res;
    }
    if(close < open){
       
        
        recursiveCall(n, open, close+1, curr + ")", res);
    }
    if(open < n){
  
        
        recursiveCall(n, open +1, close, curr + "(", res);
    }
    return res;
}
    
};
