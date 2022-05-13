/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        queue<Node*>queue;
        queue.push(root);
        while(!queue.empty()){ 
            int size = queue.size();
            Node* prev = NULL;
            for(int i = 0; i<size;i++){
                Node* temp =queue.front();
                queue.pop();
                temp->next = NULL;
                if(prev == NULL){
                    prev = temp;
                }
                else{
                    prev->next = temp;
                    temp->next = NULL;
                    prev = temp;
                }
                if(temp->left){
                    queue.push(temp->left);
                }
                if(temp->right){
                    queue.push(temp->right);
                }
            }
        }
        return root;
    }
};