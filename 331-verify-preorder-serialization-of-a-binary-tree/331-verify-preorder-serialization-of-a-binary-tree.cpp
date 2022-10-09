class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<string>stack;
        vector<string>arr;
        if(preorder.size() == 1 && preorder[0] == '#'){
            return true;
        }
        if(preorder[0] == '#')return false;
        
        string s = "";
        for(int i = 0; i<preorder.size(); i++){
            if(preorder[i] == ','){
                arr.push_back(s);
                s = "";
            }
            else{
                s+= preorder[i];
            }
        }
        arr.push_back(s);
        stack.push(arr[0]);
        stack.push(arr[0]);
        for(int i = 1; i<arr.size();i++){
            
            if(arr[i] == "#"){
                if(stack.empty()){
                    return false;
                }
                stack.pop();
            }
            else{
                if(stack.empty() == true){
                    return false;   
                }
                else{
                    stack.pop();
                    stack.push(arr[i]);
                    stack.push(arr[i]);
                }
            }
        }
        return (stack.empty());
    }
};