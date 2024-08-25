class Solution {
public:
    bool isAnagram(string s, string t) {

       if( s.length() != t.length() ) {
        return false;
       } 

        map <char,int> m;
        
        for(int i=0; i<s.length(); i++){
            if(m.find(s[i]) != m.end()){
                int count = m[s[i]];
                m[s[i]] = ++count;
            }
            else{

            m.insert({s[i], 1});
            }
        }
        map<char, int> m2;
       for(int i=0; i<t.length(); i++){
            if(m2.find(t[i]) != m2.end()){
                int count = m2[t[i]];
                m2[t[i]] = ++count;
            }
            else{

            m2.insert({t[i], 1});
            }
        }
        if(m != m2){
            return false;
        }
        return true;
        
    }
};
