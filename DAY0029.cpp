// 930. Binary Subarrays With Sum
class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            unordered_map<int ,int >hashtable;
            hashtable[0]=1;
            int count=0,sum=0;
            for(int i =0;i<nums.size();i++){
                sum+=nums[i];
                if(hashtable.find(sum-goal)!=hashtable.end()){
                    count+=hashtable[sum-goal];
                }
                hashtable[sum]++;
    
            }
            return count;
        }
    };