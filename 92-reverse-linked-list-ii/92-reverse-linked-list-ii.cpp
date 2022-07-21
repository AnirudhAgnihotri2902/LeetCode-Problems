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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL)
        return head; 


        ListNode *curr = head;
        ListNode *prev = nullptr;
        int k = 1;
        while(k<m)
        {
            prev = curr;
            curr = curr->next;
            k++;
        }

        ListNode *temp = curr->next;

        ListNode *join1 = prev, *join2 = curr;

        while(k<=n)
        { 
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            k++;
        }

        if(join1!= NULL) 
        {
            join1->next = prev;
        }
        else
        { 
            head = prev;
        }

        join2->next = curr; 
        return head;
        
    }
};