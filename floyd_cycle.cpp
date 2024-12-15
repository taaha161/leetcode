class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      // Floyds' cycle detection

      int slow = 0;
      int fast = 0;

      do{
        slow = nums[slow];
        fast = nums[nums[fast]];
      } while(slow != fast);

      int slow2= 0;

      do{
        slow2 = nums[slow2];
        slow = nums[slow];
      }while(slow2 != slow);
      return slow;
    }
};
