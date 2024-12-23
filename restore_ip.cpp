class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
            vector<string>res;
            vector<string> ipAdress;
            dfs(res, ipAdress, s, 0, 0);

            return res;
    }

    void dfs(vector<string>& res, vector<string>& ipAdress, string s, int start, int dotCount ){
        if(dotCount == 3 ){
            if(isValidIp(s.substr(start))){
                string lastpart =   s.substr(start);
                string ip;

                for(int i =0; i<ipAdress.size(); i++){
                    ip += ipAdress[i];
                    ip += '.';
                }   
                ip += lastpart;


                res.push_back(ip);
            }
            return;
        }

        for(int i = 1; i <= 3 && start + i <= s.length(); i++){
            string part = s.substr(start,i);

            if(isValidIp(part)){
                ipAdress.push_back(part);
                dfs(res, ipAdress,s, start + i, dotCount + 1);
                ipAdress.pop_back();
            }
        }
    }

   bool isValidIp(const string& s) {
        if (s.empty() || s.length() > 3) return false;
        if (s[0] == '0' && s.length() > 1) return false;
        try {
            int num = stoi(s);
            return num <= 255 && num >= 0;
        } catch (...) {
            return false;
        }
    }
};