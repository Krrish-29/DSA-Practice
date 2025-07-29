// 238. Product of Array Except Self
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size(),total=1;
        vector<int>answer(size,0);
        bool singleZero=false;
        for(auto const num:nums){
            if(num!=0) total*=num;
            else if(num==0&&!singleZero) singleZero=true;
            else return answer;
        }
        for(int i=0;i<size;i++){
            if(singleZero&&nums[i]==0) answer[i]=total;
            else if(!singleZero) answer[i]=total/nums[i];
        }
        return answer;
    }
};