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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if(head->next ==NULL){
            return NULL;
        }
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        if (slow->next== NULL){
            head->next = NULL;
            delete slow;
            return head;
        }
        ListNode *temp = slow;
        temp = slow->next;
        slow->val = temp->val;
        slow->next = temp->next;
        delete temp;
        
        return head;
    }
    
};