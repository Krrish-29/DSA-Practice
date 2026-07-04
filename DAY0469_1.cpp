// 3978. Unique Middle Element
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int size=nums.size();
        int middleElement=nums[size/2];
        bool foundOnce=false;
        for(int &num:nums){
            if(num==middleElement&&foundOnce) return false;
            if(num==middleElement) foundOnce=true;
        }
        return true;
        // can use vector<int>freq(100,0) since range is limited
        // can use unordered_map for freq for large range
        // also can use the fact that the middle element wont be seen at any other index rather than size/2;
    }
};