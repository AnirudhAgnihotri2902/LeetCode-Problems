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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *first1 = list1;
        ListNode *first2 = list2;
        ListNode *dummyhead = new ListNode(5);
        ListNode *curr = dummyhead;
        while(first1!=NULL&& first2!=NULL){
            if(first1->val<=first2->val){
                curr->next = first1;
                curr = curr->next;
                first1 = first1->next;
            }
            else{
                curr->next = first2;
                curr = curr->next;
                first2 = first2->next;
            }
        }
        if(first1!=NULL){
            curr->next = first1;
        }
        if(first2!=NULL){
            curr->next = first2;
        }
        return dummyhead->next;
        
    }
};