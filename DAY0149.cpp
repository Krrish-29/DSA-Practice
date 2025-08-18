// 3653. XOR After Range Multiplication Queries I
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int size=nums.size();
        for(auto query:queries){
            for(int i=query[0];i<=query[1]&&i<size;i+=query[2]){
                nums[i]=(1LL*nums[i]*query[3])%(int)(1e9+7);
            }
        }
        int xorSum=0;
        for(int num:nums) xorSum^=num;
        return xorSum;
    }
};