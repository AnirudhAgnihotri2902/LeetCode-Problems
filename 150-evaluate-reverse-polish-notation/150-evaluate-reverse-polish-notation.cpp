class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>stack;
        set<string>set;
        set.insert("+");
        set.insert("-");
        set.insert("*");
        set.insert("/");
        for(int i = 0; i<tokens.size(); i++){
            string str = tokens[i];
            if(set.find(str) == set.end() ){
                stack.push(stoi(str));
            }
            else{
                int first = stack.top();
                stack.pop();
                int second = stack.top();
                stack.pop();
                if(str == "*"){
                    int s = first*second;
                    stack.push(s);
                }
                else if(str == "+"){
                    int s = first+second;
                    stack.push(s);
                }
                else if(str == "/"){
                    int s = second/first;
                    stack.push(s);
                }
                else{
                    int s = second-first;
                    stack.push(s);
                }
            }
        }
        int ans = stack.top();
        return ans;
    }
};