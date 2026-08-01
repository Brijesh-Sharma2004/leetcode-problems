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
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode* dummy = new ListNode(INT_MIN);
        // dummy->next = head;
        // ListNode* curr = dummy;

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL) {
            if(curr->val == curr->next->val) {
                ListNode* p = curr->next;
                curr->next = p->next;
                delete p;
            } else {
            curr = curr->next;
            }
        }
        // ListNode* newHead = dummy->next;
        // delete dummy;
        // return newHead;
        return head;
    }
};