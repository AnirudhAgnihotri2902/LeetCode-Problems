/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        queue<Node*>queue;
        queue.push(root);
        while(!queue.empty()){
            int size = queue.size();
            vector<int>aux;
            for(int i = 0; i<size;i++){
                Node* temp = queue.front();
                queue.pop();
                aux.push_back(temp->val);
                for(auto e: temp->children){
                    if(e!=NULL){
                        queue.push(e);
                    }
                }
            }
            ans.push_back(aux);
        }
        return ans;
    }
};