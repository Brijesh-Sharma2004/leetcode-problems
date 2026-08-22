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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k==1) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* groupprev = &dummy;
        ListNode* groupHead = head;
        
        while(groupHead != NULL) {
            ListNode* kth = groupHead;

            for(int i=1; i<k; i++) {
                kth = kth->next;

                if(kth == NULL) return dummy.next;
            }
            ListNode* groupNext = kth->next;

            ListNode* prev = groupNext;
            ListNode* curr = groupHead;

            for(int i=0; i<k; i++) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            }
            groupprev->next = kth;

            groupprev = groupHead;
            groupHead = groupNext;
        }
        return dummy.next;
    }
};