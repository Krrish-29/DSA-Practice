// 3542. Minimum Operations to Convert All Elements to Zero
class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>stack;
        stack.push(0);
        int count=0;
        for(int num:nums){
            while(!stack.empty()&&stack.top()>num) stack.pop();
            if(stack.empty()||stack.top()<num){
                stack.push(num);
                count++;
            }
        }
        return count;
    }
};