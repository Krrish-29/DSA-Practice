// 84. Largest Rectangle in Histogram
// very good question of stack must try again
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        vector<int>leftSmallest(size);
        vector<int>rightSmallest(size);
        stack<int>stack;
        for(int i=0;i<size;i++){
            while(!stack.empty() && heights[stack.top()]>=heights[i]) stack.pop();
            leftSmallest[i] = (stack.empty()?-1:stack.top());
            stack.push(i);
        }
        while(!stack.empty()) stack.pop();
        for(int i=size-1;i>=0;i--){
            while(!stack.empty() && heights[stack.top()]>=heights[i]) stack.pop();
            rightSmallest[i] = (stack.empty()?size:stack.top());
            stack.push(i);
        }
        int maxArea=0,currWidth=0;
        for(int i=0;i<size;i++){
            currWidth=rightSmallest[i]-leftSmallest[i]-1;
            maxArea=max(maxArea,heights[i]*currWidth);
        }
        return maxArea;
    }
};