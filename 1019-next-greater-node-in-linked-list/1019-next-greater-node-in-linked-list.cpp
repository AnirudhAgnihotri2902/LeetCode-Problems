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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int>arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        stack<int>stack;
        int n = arr.size();
        vector<int>ans(n,0);
        for(int i = n-1; i>=0; i--){
            while(!stack.empty() && stack.top()<=arr[i]){
                stack.pop();
            }
            if(stack.empty()){
                ans[i] = 0;
            }
            else{
                ans[i] = stack.top();
            }
            stack.push(arr[i]);
        }
        return ans;
    }
};