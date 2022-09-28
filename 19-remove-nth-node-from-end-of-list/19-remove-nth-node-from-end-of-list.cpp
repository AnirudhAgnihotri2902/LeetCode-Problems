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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head;
        ListNode *secoend = head;
        int times = n;
        while(times){
            first = first->next;
            times--;
        }
        if (first == NULL){
            return head->next;
        }
        if(first == head){
            first = head;
            while(first->next!=NULL){
                first = first->next;
            }
            first->next = NULL;
            return head;
        }
        while(first->next!=NULL){
            first = first->next;
            secoend= secoend->next;
        }
        ListNode *temp = secoend->next;
        secoend->next = temp->next;
        return head;
    }
};