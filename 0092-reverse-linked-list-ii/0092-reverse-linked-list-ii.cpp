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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || left == right) {
        return head;
    }
    
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* Left = &dummy;
        ListNode* Right = &dummy;

        for(int i = 0; i<left; i++) {
            prev = Left;
            Left = Left->next;
        }
        for(int i = 0; i<right; i++) {
            Right = Right->next;
        }
        
        ListNode* p = Right->next;
        ListNode* curr = Left;
        while(p != Right) {
            ListNode* nextNode = curr->next;
            curr->next = p;
            p = curr;
            curr = nextNode; 
        }
        if(prev->next != NULL) {
        prev->next = Right;
        }

        return dummy.next;
    }
};