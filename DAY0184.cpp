// 3005. Count Elements With Maximum Frequency
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>hashmap;
        int maxVal=0;
        for(int num:nums){
            hashmap[num]++;
            maxVal=max(maxVal,hashmap[num]);
        }
        int freq=0;
        for(auto [key,val]:hashmap){
            if(val==maxVal) freq+=maxVal;
        }
        return freq;
    }
};