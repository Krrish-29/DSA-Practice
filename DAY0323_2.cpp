// 3834. Merge Adjacent Equal Elements
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        // vector<long long>stack(100000,0);
        // int idx=0;
        // for(int &num:nums){
        //     long long x=num;
        //     while(idx!=0&&stack[idx-1]==x){
        //         x*=2;
        //         idx--;
        //     }
        //     stack[idx]=x;
        //     idx++;
        // }
        // vector<long long>ans(stack.begin(),stack.begin()+idx);
        // return ans;


        vector<long long>stack;
        for(int &num:nums){
            long long x=num;
            while(!stack.empty()&&stack.back()==x){
                x*=2;
                stack.pop_back();
            }
            stack.push_back(x);
        }
        return stack;
    }
};