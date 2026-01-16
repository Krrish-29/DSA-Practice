// 85. Maximal Rectangle
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // just built upon the problem 84 of largest rectangle in histogram
        int row=matrix.size(),col=matrix[0].size();
        vector<vector<int>>heights(row,vector<int>(col,0));
        for(int j=0;j<col;j++) heights[0][j]=matrix[0][j]-'0';

        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1') heights[i][j]=(heights[i-1][j]+1);
            }
        }
        int maxArea=0;
        for(int i=0;i<row;i++){
            vector<int>leftSmallest(col);
            vector<int>rightSmallest(col);
            stack<int>stack;
            for(int j=0;j<col;j++){
                while(!stack.empty() && heights[i][stack.top()] >= heights[i][j]) stack.pop();
                leftSmallest[j]=(stack.empty()?-1:stack.top());
                stack.push(j);
            }
            while(!stack.empty()) stack.pop();
            for(int j=col-1;j>=0;j--){
                while(!stack.empty() && heights[i][stack.top()] >= heights[i][j]) stack.pop();
                rightSmallest[j]=(stack.empty()?col:stack.top());
                stack.push(j);
            }
            for(int j=0;j<col;j++){
                maxArea=max(maxArea,(rightSmallest[j]-leftSmallest[j]-1)*heights[i][j]);
            }
        }
        return maxArea;
    }
};