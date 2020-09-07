
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode* _next): val(x), next(_next){}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy; 
        while(l1 && l2){
            if(l1->val < l2->val){
                node->next = l1;
                l1 = l1->next;
            }else{
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        if(l1){
            node->next = l1;
        }
        if(l2){
            node->next = l2;
        }
        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        vector<ListNode*> list1;
        vector<ListNode*> list2;
        int length = lists.size();
        for(int i = 0; i < length /2 ;i++){
            list1.push_back(lists[i]);
        }
        for(int i = length / 2; i < length; i++){
            list2.push_back(lists[i]);
        }
        ListNode* l1 = mergeKList(list1);
        ListNode* l2 = mergeKList(list2);
        ListNode* ret = mergeTwoLists(l1,l2);
        return ret;
    }
}