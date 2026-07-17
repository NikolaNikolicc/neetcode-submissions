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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res(0);
        ListNode *tmp = &res;

        while (list1 && list2) {
            ListNode ** mark;
            if (list1->val < list2->val) {
                mark = &list1;
            } else {
                mark = &list2;
            }
            tmp->next = *mark;
            *mark = (*mark)->next;
            tmp = tmp->next;
       }
       if (list1) tmp->next = list1;
       if (list2) tmp->next = list2;

       return res.next;
    }
};