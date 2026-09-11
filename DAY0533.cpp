// 4038. Count Integers Appearing in a Single Block
class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        // store the idices of a number in nums
        // and iterate over each number and simply check if the difference b/w two idx is more than 1 
        int size=nums.size(),count=0;
        unordered_map<int,vector<int>>map;
        for(int i=0;i<size;i++){
            map[nums[i]].push_back(i);
        }
        bool contiguous;
        int prev;
        for(auto &it:map){
            contiguous=true;
            prev=-1;
            for(int &num:it.second){
                if(prev!=-1 && num-prev>1) {
                    contiguous=false;
                    break;
                }
                prev=num;
            }
            if(contiguous) count++;
        }
        return count;
    }
};