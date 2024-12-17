#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int windowSize = s1.length();
        map<char,bool> hash;
        for(int i=0 ; i<windowSize; i++){
            hash[s1[i]] = false;
        }

        int windowStart = 0;
        int windowEnd = 0;
        while(windowEnd < s2.length()){
            if(hash.find(s2[windowEnd]) == hash.end()){
                windowEnd++;
                windowStart = windowEnd;
                for(int i=0 ; i<windowSize; i++){
                     hash[s1[i]] = false;
                }
            }
          else{
              hash[s2[windowEnd]] = true;
                   
                if((windowEnd-windowStart + 1) == windowSize){
                  
                    bool found = true;
                            for(int i=0 ; i<windowSize; i++){
                               if(hash[s1[i]] == false){
                                found = false;
                               }
                              }
                    
                    if(found){
                        return true;
                    }else{
                        hash[windowStart] = false;
                         windowStart++;
                         hash[windowStart] = true;
                    }
    
                }else{
                     windowEnd++;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Basic Permutation
    // string s1_1 = "ab";
    // string s2_1 = "eidbaooo";
    // cout << "Test Case 1: " 
    //      << (solution.checkInclusion(s1_1, s2_1) ? "True" : "False") 
    //      << endl;

    // // Test Case 2: No Permutation
    // string s1_2 = "ab";
    // string s2_2 = "eidboaoo";
    // cout << "Test Case 2: " 
    //      << (solution.checkInclusion(s1_2, s2_2) ? "True" : "False") 
    //      << endl;

    // // Test Case 3: Exact Match
    // string s1_3 = "adc";
    // string s2_3 = "dcda";
    // cout << "Test Case 3: " 
    //      << (solution.checkInclusion(s1_3, s2_3) ? "True" : "False") 
    //      << endl;

    // // Test Case 4: Empty Strings
    // string s1_4 = "";
    // string s2_4 = "a";
    // cout << "Test Case 4: " 
    //      << (solution.checkInclusion(s1_4, s2_4) ? "True" : "False") 
    //      << endl;

    // // Test Case 5: Large Difference in String Lengths
    // string s1_5 = "hello";
    // string s2_5 = "ooolleoooleh";
    // cout << "Test Case 5: " 
    //      << (solution.checkInclusion(s1_5, s2_5) ? "True" : "False") 
    //      << endl;

    // Interactive Debugging
    string custom_s1, custom_s2;
    cout << "\nEnter s1: ";
    cin >> custom_s1;
    cout << "Enter s2: ";
    cin >> custom_s2;
    cout << "Custom Case: " 
         << (solution.checkInclusion(custom_s1, custom_s2) ? "True" : "False") 
         << endl;

    return 0;
}