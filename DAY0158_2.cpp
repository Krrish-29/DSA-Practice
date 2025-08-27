// 3659. Partition Array Into K-Distinct Groups
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        // int size=nums.size(),partition=size/k;
        // unordered_map<int,int>hashmap;
        // for(int num:nums){
        //     hashmap[num]++;
        //     if(hashmap[num]>partition) return false;
        // }
        // return size%k==0;
        int size=nums.size(),count=0,maximum=INT_MIN;
        if(size%k!=0) return false;
        sort(nums.begin(),nums.end());
        for(int i=1;i<size;i++){
            if(nums[i]==nums[i-1]) count++;
            else count=0;
            maximum=max(maximum,count+1);
            if(maximum>size/k) return false;
        }
        return true;
    }
};