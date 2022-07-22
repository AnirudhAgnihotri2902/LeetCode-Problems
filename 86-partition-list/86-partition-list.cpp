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
    vector<int>small;
    vector<int>larger;
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;
        while(curr!=NULL){
            if(curr->val >= x){
                larger.push_back(curr->val);
            }
            if(curr->val<x){
                small.push_back(curr->val);
            }
            curr = curr->next;
        }
        curr = head;
        for(int i = 0; i<small.size();i++){
            curr->val = small[i];
            curr = curr->next;
        }
        for(int i = 0; i<larger.size();i++){
            curr->val = larger[i];
            curr = curr->next;
        }
        return head;
    }
};