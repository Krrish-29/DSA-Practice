// 4065. Rearrange Array by Removing Distinct Values
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // using an ordered_map keep the elems and freq stored 
        // and the question asks to arrange the elems in a manner
        // where each elem is placed once in a sorted manner, and the freq of each one placed is reduced by one
        // and this pattern repeats , for that use an iterator on map and skip elems having 0 freq 
        // and when the iterator reaches the end, place it back at beginning , and repeat till i reaches 
        // number of elems in original array 
        map<int,int>map;//value and freq
        for(auto &num:nums) map[num]++;
        int i = 0,size = nums.size();
        auto it = map.begin();
        while(i<size){
            if(it->second != 0){
                nums[i++] = it->first;
                it->second--;
            } 
            ++it;
            if(it == map.end()) it = map.begin();
        }
        return nums;
    }
};