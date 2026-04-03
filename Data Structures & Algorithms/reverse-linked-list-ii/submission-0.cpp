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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next){
            newHead = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
        }
        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = 1;
        ListNode* curr = head;

        // find nth element
        ListNode* prevLeft = new ListNode(-1, head), * nextRight = nullptr;
        while (curr && cnt != left) {
            prevLeft = curr;
            curr = curr->next;
            cnt++;
        }

        while (curr && cnt != right) {
            curr = curr->next;
            cnt++;
        }
        nextRight = curr->next;
        curr->next = nullptr;

        ListNode* newHead = reverseList(prevLeft->next);
        if (prevLeft->next == head) {
            head = newHead;
        }

        prevLeft->next->next = nextRight;
        prevLeft->next = newHead;

        return head;

    }
};