/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *curr = node;;
        ListNode *temp = node;;
        temp = curr->next;
        curr->val = temp->val;
        curr->next = temp->next;
        delete temp;
        node = curr;
        
    }
};