// 2958. Length of Longest Subarray With at Most K Frequency
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // simple two pointer keep a map of freq starting from left to right and if any elem exceeds the 
        // k minimize till the freq of that elem is == to k , montior maxlen at each step
        int left=0,right=0,size=nums.size(),len=0;
        unordered_map<int,int>freqMap;
        while(right<size){
            freqMap[nums[right]]++;
            while(freqMap[nums[right]] > k){
                freqMap[nums[left]]--;
                left++;
            }
            right++;
            len = max(len,right-left);
        }
        return len;
    }
};