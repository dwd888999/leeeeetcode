/** leetcode 82 Remove Duplicates from Sorted List II
 * Definition for singly-linked list.
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        if(head==NULL || head->next==NULL) return head;
        ListNode* node = head->next;
        if(head->val!=node->val){
            dummy->next = head;
            head->next = deleteDuplicates(node);
        }else{
            while(node!=NULL && node->val == head->val){
                node=node->next;
            }
            dummy->next = deleteDuplicates(node);
        }
        return dummy->next;
        
    }
};