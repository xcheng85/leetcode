class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> myStack; 
        myStack.push(-1);
        int maxArea = 0; 
        
        for(int i = 0; i < heights.size(); i++){
            while(myStack.top() != -1 && heights[myStack.top()] >= heights[i]){
                int topIdx = myStack.top(); 
                // new histogram is shorter, 
               
                    myStack.pop(); 
                    maxArea = max(maxArea, heights[topIdx] * (i - myStack.top() - 1));
                
            }
            myStack.push(i);
        }
        
        while(myStack.top() != -1){
            int topIdx = myStack.top(); 
            myStack.pop();
            maxArea = max(maxArea, heights[topIdx] * ((int)heights.size() - myStack.top() - 1));
        }
        
        return maxArea;
    }
};