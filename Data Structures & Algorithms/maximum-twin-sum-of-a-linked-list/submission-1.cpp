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
    ListNode *findMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // unchain first half from second one
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *curr = head, *tmp;
        while (curr) {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    int findSum(ListNode *head1, ListNode *head2) {
        int maxSum = 0;
        while (head1 && head2) {
            maxSum = max(head1->val + head2->val, maxSum);
            head1 = head1->next;
            head2 = head2->next;
        }
        return maxSum;
    }

    int pairSum(ListNode* head) {
        // find middle 
        ListNode *middle = findMiddle(head);
        // reverse list
        ListNode *secondList = reverseList(middle);
        // find sum
        return findSum(head, secondList);
    }
};