// 46. Permutations
class Solution {
    public:
        void helper(vector<int>& nums,int index,vector<vector<int>>&answer){
            if(index>=nums.size()){
                answer.push_back(nums);
                return ;
            }
            for(int i=index;i<nums.size();i++){
                swap(nums[index],nums[i]);
                helper(nums,index+1,answer);
                swap(nums[index],nums[i]);
            }
        }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>>answer;
            helper(nums,0,answer);
            return answer;
        }
    };


    // lexicographic next-permutation approach
    // 1. Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, the permutation is the last permutation.
    // 2. Find the largest index l greater than k such that nums[k] < nums[l].
    // 3. Swap the value of nums[k] with that of nums[l].
    // 4. Reverse the sequence from nums[k + 1] up to and including the final element nums[nums.size() - 1].
    // 5. Return the next permutation.
    // 6. If the permutation is the last permutation, return the first permutation.
    // 7. Repeat the process until all permutations are generated.
    // 8. The time complexity of this algorithm is O(n!), where n is the number of elements in the input array.
    // 9. The space complexity is O(1) since we are modifying the input array in place.
    // 10. The algorithm is efficient and works well for generating permutations of small to medium-sized arrays.
    // 11. The algorithm is not suitable for generating permutations of large arrays due to its exponential time complexity.
    class Solution {
        public:
            vector<vector<int>> permute(vector<int>& nums) {
                sort(nums.begin(), nums.end());
        
                vector<vector<int>> r(factorial(nums.size()), vector<int>(nums.size()));
        
                int cnt = 0;
                copy(nums.begin(), nums.end(), r[cnt++].begin());
                while (nextPermutation(nums)) {
                    copy(nums.begin(), nums.end(), r[cnt++].begin());
                }
        
                return r;
            }
        private:
        
            int factorial(int n) {
                if (n == 1)
                    return 1;
                return n * factorial(n - 1);
            }
        
            bool nextPermutation(vector<int>& nums) {
                for (int i = nums.size() - 1; i > 0; --i) {
        
                    if (nums[i - 1] < nums[i]) {
                        int min = nums[i], minPos = i;
                        for (int j = i + 1; j < nums.size(); ++j) {
                            if (nums[j] < min && nums[j] > nums[i - 1]) {
                                minPos = j;
                                min = nums[j];
                            }
                        }
                        swap(nums[i - 1], nums[minPos]);
                        sort(nums.begin() + i, nums.end());
                        return true;
                    }
                }
                return false;
            }
        
        };