// 4049. Count Values With Equally Spaced Occurrences II
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        // simple solution , store the idices of each num
        // then if idices > 3 calculate diff b/w consecutives and verify if diff is same
        unordered_map<int,vector<int>>map; // num , idices
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        int count=0,gap;
        bool special;
        for(auto &it:map){
            if(it.second.size()<3) continue;
            gap = it.second[1]-it.second[0];
            special = true;
            for(int i=1;i<it.second.size();i++){
                if(it.second[i]-it.second[i-1] != gap) {
                    special = false;
                    break;
                }
            }
            if(special) count++;
        }
        return count;
    }
};