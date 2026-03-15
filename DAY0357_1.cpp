// 3866. First Unique Even Element
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int>map;
        for(auto &num:nums){
            if(num%2==0){
                map[num]++;
            }
        }
        for(auto &num:nums){
            if(num%2==0&&map[num]==1) return num;
        }
        return -1;
    }
};