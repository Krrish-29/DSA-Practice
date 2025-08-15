// 2149. Rearrange Array Elements by Sign
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int>pos;
        queue<int>neg;
        for(int num:nums){
            if(num>0) pos.push(num);
            else neg.push(num);
        }
        nums.clear();
        while(!pos.empty()&&!neg.empty()){
            nums.push_back(pos.front());
            nums.push_back(neg.front());
            pos.pop();
            neg.pop();
        }
        return nums;
    }
};