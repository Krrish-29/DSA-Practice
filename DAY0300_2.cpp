// 739. Daily Temperatures
class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // new solutions
        // stack<pair<int,int>>stack;
        // int size = temperatures.size();
        // for(int i=0;i<size;i++){
        //     while(!stack.empty() && stack.top().first < temperatures[i]){
        //         auto topTemp=stack.top();
        //         temperatures[topTemp.second] = i - topTemp.second;
        //         stack.pop();
        //     }
        //     stack.push({temperatures[i],i});
        // }
        // while(!stack.empty()){
        //     auto topTemp=stack.top();
        //     temperatures[topTemp.second] = 0;
        //     stack.pop();
        // }
        // return temperatures;
        
        stack<int>stack;
        int size = temperatures.size();
        for(int i=0;i<size;i++){
            while(!stack.empty() && temperatures[stack.top()] < temperatures[i]){
                temperatures[stack.top()] = i - stack.top();
                stack.pop();
            }
            stack.push(i);
        }
        while(!stack.empty()){
            temperatures[stack.top()] = 0;
            stack.pop();
        }
        return temperatures;

        // old solutions 
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

        // stack<int>stack;
        // int size=temperatures.size();
        // vector<int>ans(size,0);
        // stack.push(0);
        // for(int i=1;i<size;i++){
        //     while(!stack.empty()&&temperatures[stack.top()]<temperatures[i]) {
        //         ans[stack.top()]=i-stack.top();
        //         stack.pop();
        //     }
        //     stack.push(i);
        // }
        // return ans;
    }
};