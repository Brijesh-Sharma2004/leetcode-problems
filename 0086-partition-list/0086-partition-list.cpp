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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        ListNode* lessHead = NULL;
        ListNode* lessTail = NULL;
        ListNode* greaterHead = NULL;
        ListNode* greaterTail = NULL;
        ListNode* curr = head;

        while(curr != NULL) {
            if(curr->val < x) {
                if(lessHead == NULL) {
                    lessHead = curr;
                    lessTail = curr;
                } else {
                    lessTail->next = curr;
                    lessTail = curr;
                }
            } else {
                if(greaterHead == NULL) {
                    greaterHead = curr;
                    greaterTail = curr;
                } else {
                    greaterTail->next = curr;
                    greaterTail = curr;
                }
            }
            curr = curr->next;
        }
        if(greaterTail == NULL) return lessHead;
        
        greaterTail->next = NULL;
        if(lessTail == NULL) {
            return greaterHead;
        }

        lessTail->next = greaterHead;
        return lessHead;
    }
};