class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] != "+"  && tokens[i] !=  "-" && tokens[i] != "/" && tokens[i] != "*" ){
                stck.push(stoi(tokens[i]));
            }
            else{
                int rightOp = stck.top();
                stck.pop();
                int leftOp = stck.top();
                stck.pop();
                if(tokens[i] == "+"){
                   int result = leftOp + rightOp;
                   stck.push(result);
                }
                if(tokens[i] == "-"){
                   int result = leftOp - rightOp;
                   stck.push(result);
                }
                if(tokens[i] == "*"){
                   int result = leftOp * rightOp;
                   stck.push(result);
                }
                if(tokens[i] == "/"){
                   int result = leftOp / rightOp;
                   stck.push(result);
                }
            }
        }
        return stck.top();
        
    }
};
