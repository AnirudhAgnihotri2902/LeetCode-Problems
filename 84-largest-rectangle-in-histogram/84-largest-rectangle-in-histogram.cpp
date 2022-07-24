class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>stack;
        int maxA = 0;
        for(int i = 0; i<=n; i++){
            while(!stack.empty() && (i == n || heights[stack.top()]>=heights[i])){
                int height = heights[stack.top()];
                stack.pop();
                int width;
                if(stack.empty()){
                    width = i;
                }
                else{
                    width = i-stack.top()-1;
                }
                maxA = max(maxA,(width*height));
            }
            stack.push(i);
        }
        return maxA;
    }
};