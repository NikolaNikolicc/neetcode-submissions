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

    ListNode* mergetwo(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(), * res = &dummy;
        ListNode** ptr;
        while (l1 && l2) {
            if (l1->val <= l2->val) ptr = &l1;
            else ptr = &l2;
            
            res->next = *ptr;
            *ptr = (*ptr)->next;
            res = res->next;
        }

        if (l1) res->next = l1;
        if (l2) res->next = l2;

        return dummy.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        
        ListNode* res = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            res = mergetwo(res, lists[i]);
        }

        return res;
    }
};
