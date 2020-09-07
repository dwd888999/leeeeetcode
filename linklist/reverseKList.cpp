
// leetcode 25 Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;
        
        for(int i = 0; i < k;i++){
            node = node->next;
            if(node == NULL) return head;
        }
        ListNode* next = node->next;
        
        node->next = NULL;
        ListNode* ret = reverseList(head);
        
        head->next = reverseKGroup(next, k);
        return ret;
        
        
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* node = head;
        while(node!=NULL){
            ListNode* next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
    
};