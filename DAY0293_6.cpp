// 448. Find All Numbers Disappeared in an Array
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size=nums.size();
        vector<int>map(size,0);
        for(int num:nums) map[num-1]=1;
        nums.resize(0);
        for(int i=0;i<size;i++) if(map[i]==0) nums.push_back(i+1);
        map.resize(0);
        return nums;
    }
};