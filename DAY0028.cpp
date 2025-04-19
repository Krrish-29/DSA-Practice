// 2563. Count the Number of Fair Pairs
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long answer = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int leftBound = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int rightBound = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            answer += (rightBound - leftBound);
        }
        return answer;
    }
};
