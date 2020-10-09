

// �ж��������Ƿ��л�


class Solution{
public:
    bool hasCycle(ListNode* root){
        ListNode* fast = root; 
        ListNode* slow = root;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }
        return false;
    }
}