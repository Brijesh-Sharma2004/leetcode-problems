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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;

        ListNode* len = head;
        int length = 1;

        while(len->next != NULL) {
            length++;
            len = len->next;
        }
        k = k % length;
        len->next = head;
        ListNode* curr = head;

        for(int i=1; i<length - k; i++) {
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL;

        return newHead;
    }
};