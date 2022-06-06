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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr = headA;
        int lengthA = 0;
        int lengthB = 0;
        while(curr!=NULL){
            lengthA+=1;
            curr = curr->next;
        }
        curr= headB;
        while(curr!=NULL){
            lengthB++;
            curr = curr->next;
        }
        ListNode* first = headA;
        ListNode* second = headB;
        if(lengthA>lengthB){
            int diff = lengthA-lengthB;
            for(int i = 0; i<diff;i++){
                first = first->next;
            }
        }
        if(lengthA<lengthB){
            int diff = lengthB-lengthA;
            for(int i = 0; i<diff;i++){
                second = second->next;
            }
        }
        while(first!=NULL){
            if(first == second){
                return first;
            }
            first = first->next;
            second = second->next;
        }
        
        return NULL;
    }
};