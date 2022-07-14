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
        ListNode* curr = head;
        int count=0;
        for(int i = 0; i < k; i++){
            if(curr == NULL) break;
            curr = curr->next;
            count++;
        }
        if(count%2 == 1 && curr == NULL){
            return head;
        }
        if(count%2 == 1 && curr !=NULL){
            ListNode* temp = head;
            while(temp->next!= curr){
                temp = temp->next;
            }
            temp->next =  reverseKGroup(curr, k+1);
            return head;
        }
        curr = head;
        ListNode* prev = NULL;
        for(int i = 0; i < k && curr!=NULL; i++){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(count<k || curr == NULL){
            return prev;
        }
        head->next = reverseKGroup(curr, k+1);
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        head->next = reverseKGroup(head->next, 2);
        return head;
    }
};