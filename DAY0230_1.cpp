// 739. Daily Temperatures
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // stack<pair<int,int>>stack;
        // int size=temperatures.size();
        // vector<int>ans(size,0);
        // stack.push({temperatures[0],0});
        // for(int i=1;i<size;i++){
        //     while(!stack.empty()&&stack.top().first<temperatures[i]) {
        //         ans[stack.top().second]=i-stack.top().second;
        //         stack.pop();
        //     }
        //     stack.push({temperatures[i],i});
        // }
        // return ans;
        stack<int>stack;
        int size=temperatures.size();
        vector<int>ans(size,0);
        stack.push(0);
        for(int i=1;i<size;i++){
            while(!stack.empty()&&temperatures[stack.top()]<temperatures[i]) {
                ans[stack.top()]=i-stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        return ans;
    }
};