class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        set<int> s(nums.begin(), nums.end());
        int maxLength = 0;

        for (int num : s) {
            // Check if it's the start of a sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                maxLength = max(maxLength, currentStreak);
            }
        }

        return maxLength;
    }
};
