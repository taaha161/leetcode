/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = new ListNode(0,head);
        ListNode* leftPtr = node;
        ListNode* rightPtr= head;
        for(int i=0; i<n; i++){
            rightPtr = rightPtr->next;
        }
        while(rightPtr){
           rightPtr = rightPtr->next;
           leftPtr= leftPtr->next;
        }
        leftPtr->next = leftPtr->next->next;

        return node->next;
        
      
    }

 
};
