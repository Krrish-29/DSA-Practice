// 3432. Count Partitions with Even Sum Difference
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        //simple approach
        // int total=0,count=0,temp=0;
        // for(int num:nums) total+=num;
        // for(int num:nums){
        //     temp+=num;
        //     if((temp!=total)&&(total-2*temp)%2==0) count++;
        // }
        // return count;

        // prefix sum 
        int size=nums.size(),count=0;
        for(int i=1;i<size;i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<size-1;i++){
            if((2*nums[i]-nums[size-1])%2==0) count++;
        }
        return count;
    }
};