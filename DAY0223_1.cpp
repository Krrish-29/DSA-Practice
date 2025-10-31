// 3289. The Two Sneaky Numbers of Digitville
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        vector<int>map(nums.size()-1,0);
        for(int num:nums){
            if(map[num]!=0) ans.push_back(num);
            map[num]++;
        }   
        return ans;
    }
};