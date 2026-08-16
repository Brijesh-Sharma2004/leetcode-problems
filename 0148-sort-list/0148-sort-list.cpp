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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* right = slow->next;
        slow->next = NULL;

        ListNode* left = sortList(head);
        right = sortList(right);

        if (left == NULL) return right;

        if (right == NULL) return left;

        ListNode* newHead = NULL;

        if(left->val < right->val) {
            newHead = left;
            left = left->next;
        } else {
            newHead = right;
            right = right->next;
        }

        ListNode* tail = newHead;

        while(left != NULL && right != NULL) {
            if(left->val < right->val) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
        }

        if(left != NULL) {
            tail->next = left;
        } else {
            tail->next = right;
        }

        return newHead;
    }
};