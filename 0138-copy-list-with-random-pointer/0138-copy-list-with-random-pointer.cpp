/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node* originalHead = head;
        unordered_map<Node* , Node* > mpp;

        while(head != NULL) {
            Node* newNode = new Node(head->val);
            mpp[head] = newNode;
            head = head->next;
        }
        
        head = originalHead;

        while(head != NULL) {
            mpp[head]->next = mpp[head->next];

            if(head->random != NULL)
            mpp[head]->random = mpp[head->random];
            
            head = head->next;             
        }
        return mpp[originalHead];
    }
};